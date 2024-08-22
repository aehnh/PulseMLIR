#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/SCF/SCF.h"
#include "mlir/Dialect/StandardOps/IR/Ops.h"
#include "mlir/Transforms/DialectConversion.h"

#include "Conversion/QASMToPulse/Passes.h"
#include "Dialect/QASM/QASMDialect.h"
#include "Dialect/QASM/QASMOps.h"
#include "Dialect/Pulse/PulseDialect.h"
#include "Dialect/Pulse/PulseOps.h"
#include "PassDetail.h"

using namespace mlir;

class QubitMap {
  [[maybe_unused]] MLIRContext *ctx;
  llvm::StringMap<DenseMap<Value, std::tuple<Value, Value, Value, Value>>> mapping;

public:
  QubitMap(MLIRContext *ctx)
      : ctx(ctx), mapping() {}
      
  void setMapping(FuncOp func, Value qubit, std::vector channels) {
    mapping[func.getName()][qubit] = channels;
  }

  std::tuple<Value, Value, Value, Value> resolveQubit(FuncOp func, Value qubit) {
    return mapping[func.getName()][qubit];
  }
};

namespace {

class QASMTypeConverter : public TypeConverter {
public:
  using TypeConverter::convertType;

  QASMTypeConverter(MLIRContext *context) : context(context) {
    addConversion([](Type type) { return type; });
  }
  MLIRContext *getContext() const { return context; }

private:
  MLIRContext *context;
};

/// Base Pattern
template <typename SourceOp>
class QASMOpToPulseConversionPattern : public OpConversionPattern<SourceOp> {
protected:
  QubitMap *qubitMap;
  MLIRContext *ctx;

public:
  using OpConversionPattern<SourceOp>::OpConversionPattern;
  QASMOpToPulseConversionPattern(QASMTypeConverter &typeConverter,
                                   QubitMap *qubitMap,
                                   PatternBenefit benefit = 1)
      : OpConversionPattern<SourceOp>(typeConverter, typeConverter.getContext(),
                                      benefit),
        qubitMap(qubitMap), ctx(typeConverter.getContext()) {}
};

//====== PATTERNS ======

/// %q0 = qasm.allocate
/// [[to]]
/// %dc0, %cc0, %mc0, %ac0 = pulse.initialize_channels() : (!pulse.drive_channel, !pulse.control_channel, !pulse.measure_channel, !pulse.acquire_channel)
class AllocateOpConversion
    : public QASMOpToPulseConversionPattern<QASM::AllocateOp> {
public:
  using QASMOpToPulseConversionPattern::QASMOpToPulseConversionPattern;
  LogicalResult
  matchAndRewrite(QASM::AllocateOp op, ArrayRef<Value> operands,
                  ConversionPatternRewriter &rewriter) const override {
    auto initChannelsOp = rewriter.create<pulse::InitializeChannelsOp>(
      op->getLoc(),
      {
        pulse::DriveChannelType,
        pulse::ControlChannelType,
        pulse::MeasureChannelType,
        pulse::AcquireChannelType
      },
      ValueRange{}
    );
    std::vector results = {
      initChannelsOp.getResult(0),
      initChannelsOp.getResult(1),
      initChannelsOp.getResult(2),
      initChannelsOp.getResult(3)
    }
    qubitMap->setMapping(
      op->getParentOfType<FuncOp>(),
      op.qout(),
      results
    );
    rewriter.eraseOp(op);
    return success();
  }
};

/// %res = qasm.measure %q0
/// [[to]]
/// %dur = constant 1472 : i32
/// %sig = constant 64 : i32
/// %width = constant 1216 : i32
/// %amp = constant 0.23564 : f64
/// %angle = -1.9104095842958464 : f64
/// %wav = pulse.gaussian_square(%dur, %sig, %width, %amp, %angle) : (i32, i32, i32, f64, f64) -> !pulse.waveform
/// pulse.play(%wav, %mc0) : (!pulse.waveform, !pulse.drive_channel)
/// %dur1 = constant 1568 : i32
/// pulse.delay(%dur1, %mc0) : (i32, !pulse.drive_channel)
/// %res = pulse.acquire(%dur, %ac0) : (i1, !pulse.drive_channel)
class MeasureOpConversion
    : public QASMOpToPulseConversionPattern<QASM::MeasureOp> {
public:
  using QASMOpToPulseConversionPattern::QASMOpToPulseConversionPattern;
  LogicalResult
  matchAndRewrite(QASM::MeasureOp op, ArrayRef<Value> operands,
                  ConversionPatternRewriter &rewriter) const override {
    QASM::MeasureOpAdaptor args(operands);
    auto parentFuncOp = op->getParentOfType<FuncOp>();
    auto channels = qubitMap->resolveQubit(parentFuncOp, args.qinp());
    auto measureChannel = channels[2];
    auto acquireChannel = channels[3];
    auto loc = op->getLoc();

    auto dur = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(1472));
    auto sig = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(64));
    auto width = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(1216));
    auto amp = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.23564));
    auto angle = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(-1.9104095842958464));
    auto wav = rewriter.create<pulse::GaussianSquareOp>(loc, pulse::WaveformType, dur, sig, width, amp, angle);
    rewriter.create<pulse::PlayOp>(loc, wav, measureChannel);
    auto dur1 = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(1568));
    rewriter.create<pulse::DelayOp>(loc, dur1, measureChannel);
    auto res = rewriter.create<pulse::AcquireOp>(loc, rewriter.getI1Type(), dur, acquireChannel);

    rewriter.replaceOp(op, result.getResult());
    return success();
  }
};

/// qasm.reset %q
/// [[to]]
/// %dur = constant 1472 : i32
/// %sig = constant 64 : i32
/// %width = constant 1216 : i32
/// %amp = constant 0.23564 : f64
/// %angle = -1.9104095842958464 : f64
/// %wav = pulse.gaussian_square(%dur, %sig, %width, %amp, %angle) : (i32, i32, i32, f64, f64) -> !pulse.waveform
/// pulse.play(%wav, %mc0) : (!pulse.waveform, !pulse.drive_channel)
/// %dur1 = constant 1568 : i32
/// pulse.delay(%dur1, %mc0) : (i32, !pulse.drive_channel)
/// %res = pulse.acquire(%dur, %ac0) : (i1, !pulse.drive_channel)
class ResetOpConversion
    : public QASMOpToPulseConversionPattern<QASM::ResetOp> {
public:
  using QASMOpToPulseConversionPattern::QASMOpToPulseConversionPattern;
  LogicalResult
  matchAndRewrite(QASM::ResetOp op, ArrayRef<Value> operands,
                  ConversionPatternRewriter &rewriter) const override {
    QASM::ResetOpAdaptor args(operands);
    auto parentFuncOp = op->getParentOfType<FuncOp>();
    auto channels = qubitMap->resolveQubit(parentFuncOp, args.qinp());
    auto measureChannel = channels[2];
    auto acquireChannel = channels[3];
    auto loc = op->getLoc();

    auto dur = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(1472));
    auto sig = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(64));
    auto width = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(1216));
    auto amp = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.23564));
    auto angle = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(-1.9104095842958464));
    auto wav = rewriter.create<pulse::GaussianSquareOp>(loc, pulse::WaveformType, dur, sig, width, amp, angle);
    rewriter.create<pulse::PlayOp>(loc, wav, measureChannel);
    auto dur1 = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(1568));
    rewriter.create<pulse::DelayOp>(loc, dur1, measureChannel);
    auto res = rewriter.create<pulse::AcquireOp>(loc, rewriter.getI1Type(), dur, acquireChannel);

    rewriter.eraseOp(op);
    return success();
  }
};

/// qasm.barrier %q0
/// [[to]]
/// pulse.barrier %dc0, %cc0, %mc0, %ac0
class BarrierOpConversion
    : public QASMOpToPulseConversionPattern<QASM::BarrierOp> {
public:
  using QASMOpToPulseConversionPattern::QASMOpToPulseConversionPattern;
  LogicalResult
  matchAndRewrite(QASM::BarrierOp op, ArrayRef<Value> operands,
                  ConversionPatternRewriter &rewriter) const override {
    QASM::BarrierOpAdaptor args(operands);
    auto parentFuncOp = op->getParentOfType<FuncOp>();
    auto channels = qubitMap->resolveQubit(parentFuncOp, args.qinp());
    rewriter.create<pulse::BarrierOp>(op->getLoc(), channels);
    rewriter.eraseOp(op);
    return success();
  }
};

/// qasm.U(%theta : f*, %phi : f*, %lambda : f*) %q0
/// [[to]]
/// %pha = negf %lambda : f64
/// pulse.shift_phase(%pha, %dc0) : (f64, !pulse.drive_channel)
/// %dur = constant 160 : i32
/// %sig = constant 40 : i32
/// %beta = constant 0.7190255528759942 : f64
/// %amp = constant 0.08981286442437861 : f64
/// %angle = constant -0.003949372005175009 : f64
/// %wav = pulse.drag(%dur, %sig, %beta, %amp, %angle) : (i32, i32, f64, f64, f64) -> !pulse.waveform
/// pulse.play(%wav, %dc0) : (!pulse.waveform, !pulse.drive_channel)
/// %tmp = negf %theta : f64
/// %tmp1 = constant 3.14159265358979 : f64
/// %pha1 = subf %tmp, %tmp1 : f64
/// pulse.shift_phase(%pha1, %dc0) : (f64, !pulse.drive_channel)
/// %wav1 = pulse.drag(%dur, %sig, %beta, %amp, %angle) : (i32, i32, f64, f64, f64) -> !pulse.waveform
/// pulse.play(%wav1, %dc0) : (!pulse.waveform, !pulse.drive_channel)
/// %tmp2 = negf %phi : f64
/// %tmp3 = constant 9.42477796076938 : f64
/// %pha2 = subf %tmp2, %tmp3 : f64
/// pulse.shift_phase(%pha2, %dc0) : (f64, !pulse.drive_channel)
class SingleQubitRotationOpConversion
    : public QASMOpToPulseConversionPattern<QASM::SingleQubitRotationOp> {
public:
  using QASMOpToPulseConversionPattern::QASMOpToQuantumConversionPattern;
  LogicalResult
  matchAndRewrite(QASM::SingleQubitRotationOp op, ArrayRef<Value> operands,
                  ConversionPatternRewriter &rewriter) const override {
    QASM::SingleQubitRotationOpAdaptor args(operands);
    auto func = op->getParentOfType<FuncOp>();
    auto channels = qubitMap->resolveQubit(func, args.qinp());
    auto driveChannel = channels[0];
    auto loc = op->getLoc();

    auto pha = rewriter.create<NegFOp>(loc, args.lambda());
    rewriter.create<pulse::ShiftPhaseOp>(loc, pha, driveChannel);
    auto dur = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(160));
    auto sig = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(40));
    auto beta = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.7190255528759942));
    auto amp = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.08981286442437861));
    auto angle = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(-0.003949372005175009));
    auto wav = rewriter.create<pulse::DragOp>(loc, dur, sig, beta, amp, angle);
    rewriter.create<pulse::PlayOp>(loc, wav, driveChannel);
    auto tmp = rewriter.create<NegFOp>(loc, args.theta());
    auto tmp1 = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(3.14159265358979));
    auto pha1 = rewriter.create<SubFOp>(loc, tmp, tmp1);
    rewriter.create<pulse::ShiftPhaseOp>(loc, pha1, driveChannel);
    auto wav1 = rewriter.create<pulse::DragOp>(loc, dur, sig, beta, amp, angle);
    rewriter.create<pulse::PlayOp>(loc, wav1, driveChannel);
    auto tmp2 = rewriter.create<NegFOp>(loc, args.phi());
    auto tmp3 = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(9.42477796076938));
    auto pha2 = rewriter.create<SubFOp>(loc, tmp2, tmp3);
    rewriter.create<pulse::ShiftPhaseOp>(loc, pha2, driveChannel);

    rewriter.eraseOp(op);
    return success();
  }
};

/// qasm.CX %q0, %q1
/// [[to]]
/// %pha = constant 1.5707963267948966 : f64
/// pulse.shift_phase(%pha, %dc0) : (f64, !pulse.drive_channel)
/// pulse.shift_phase(%pha, %cc1) : (f64, !pulse.control_channel)
/// %dur = constant 160 : i32
/// %sigma = constant 40 : i32
/// %beta = constant 0.7171287840008055 : f64
/// %amp = constant 0.1797336637124058 : f64
/// %angle = constant -1.5707963267948968 : f64
/// %wav = pulse.drag(%dur, %sigma, %beta, %amp, %angle) : (i32, i32, f64, f64, f64) -> !pulse.waveform
/// pulse.play(%wav, %dc0)
/// %beta2 = constant -0.6677267548609104 : f64
/// %amp2 = constant 0.08451179589418657 : f64
/// %angle2 = constant 0.00495799629351078 : f64
/// %wav2 = pulse.drag(%dur, %sigma, %beta2, %amp2, %angle2) : (i32, i32, f64, f64, f64) -> !pulse.waveform
/// pulse.play(%wav2, %dc1)
/// %dur3 = constant 512 : i32
/// %sigma3 = constant 64 : i32
/// %width3 = constant 256 : i32
/// %amp3 = constant 0.06111098055028464 : f64
/// %angle3 = constant 0.0002906564659721502 : f64
/// %wav3 = pulse.gaussian_square(%dur3, %sigma3, %width3, %amp3, %angle3) : (i32, i32, i32, f64, f64) -> !pulse.waveform
/// pulse.play(%wav3, %dc1)
/// %amp4 = constant 0.39758741702842126 : f64
/// %angle4 = constant -2.179855933078848 : f64
/// %wav4 = pulse.gaussian_square(%dur3, %sigma3, %width3, %amp4, %angle4) : (i32, i32, i32, f64, f64) -> !pulse.waveform
/// pulse.play(%wav4, %cc0)
/// %angle5 = constant 0.0 : f64
/// %wav5 = pulse.drag(%dur, %sigma, %beta, %amp, %angle5) : (i32, i32, f64, f64, f64) -> !pulse.waveform
/// pulse.play(%wav5, %dc0)
/// angle6 = constant -3.141301997123821 : f64
/// %wav6 = pulse.gaussian_square(%dur3, %sigma3, %width3, %amp3, %angle6) : (i32, i32, i32, f64, f64) -> !pulse.waveform
/// pulse.play(%wav6, %dc1)
/// %angle7 = constant 0.9617367205109453 : f64
/// %wav7 = pulse.gaussian_square(%dur3, %sigma3, %width3, %amp4, %angle7) : (i32, i32, i32, f64, f64) -> !pulse.waveform
/// pulse.play(%wav7, %cc0)
class ControlledNotOpConversion
    : public QASMOpToPulseConversionPattern<QASM::ControlledNotOp> {
public:
  using QASMOpToPulseConversionPattern::QASMOpToPulseConversionPattern;
  LogicalResult
  matchAndRewrite(QASM::ControlledNotOp op, ArrayRef<Value> operands,
                  ConversionPatternRewriter &rewriter) const override {
    QASM::ControlledNotOpAdaptor args(operands);
    auto func = op->getParentOfType<FuncOp>();
    auto cont_channels = qubitMap->resolveQubit(func, args.qinp0());
    auto targ_channels = qubitMap->resolveQubit(func, args.qinp1());
    auto dc0 = cont_channels[0];
    auto cc0 = cont_channels[1];
    auto dc1 = targ_channels[0];
    auto cc1 = targ_channels[1];
    auto loc = op->getLoc();

    auto pha = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(1.5707963267948966));
    rewriter.create<pulse::ShiftPhaseOp>(loc, pha, dc0);
    rewriter.create<pulse::ShiftPhaseOp>(loc, pha, cc1);
    auto dur = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(160));
    auto sigma = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(40));
    auto beta = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.7171287840008055));
    auto amp = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.1797336637124058));
    auto angle = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(-1.5707963267948968));
    auto wav = rewriter.create<pulse::DragOp>(loc, dur, sigma, beta, amp, angle);
    rewriter.create<pulse::PlayOp>(loc, wav, dc0);
    auto beta2 = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(-0.6677267548609104));
    auto amp2 = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.08451179589418657));
    auto angle2 = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.00495799629351078));
    auto wav2 = rewriter.create<pulse::DragOp>(loc, dur, sigma, beta2, amp2, angle2);
    rewriter.create<pulse::PlayOp>(loc, wav2, dc1);
    auto dur3 = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(512));
    auto sigma3 = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(64));
    auto width3 = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(256));
    auto amp3 = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.06111098055028464));
    auto angle3 = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.0002906564659721502));
    auto wav3 = rewriter.create<pulse::GaussianSquareOp>(loc, dur3, sigma3, width3, amp3, angle3);
    rewriter.create<pulse::PlayOp>(loc, wav3, dc1);
    auto amp4 = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.39758741702842126));
    auto angle4 = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(-2.179855933078848));
    auto wav4 = rewriter.create<pulse::GaussianSquareOp>(loc, dur3, sigma3, width3, amp4, angle4);
    rewriter.create<pulse::PlayOp>(loc, wav4, cc0);
    auto angle5 = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.0));
    auto wav5 = rewriter.create<pulse::DragOp>(loc, dur, sigma, beta, amp, angle5);
    rewriter.create<pulse::PlayOp>(loc, wav5, dc0);
    auto angle6 = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(-3.141301997123821));
    auto wav6 = rewriter.create<pulse::GaussianSquareOp>(loc, dur3, sigma3, width3, amp3, angle6);
    rewriter.create<pulse::PlayOp>(loc, wav6, dc1);
    auto angle7 = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.9617367205109453));
    auto wav7 = rewriter.create<pulse::GaussianSquareOp>(loc, dur3, sigma3, width3, amp4, angle7);
    rewriter.create<pulse::PlayOp>(loc, wav7, cc0);

    rewriter.eraseOp(op);
    return success();
  }
};

/// Convert a QASM gate declaration
/// Form: @<gate-name>([AnyFloat...], [QASM::QubitType...]) -> ()
/// [[to]]
/// @<gate-name>([AnyFloat...], [pulse::DriveChannel, pulse::ControlChannel, pulse::MeasureChannel, pulse::AcquireChannel...])
class FuncOpConversion : public QASMOpToPulseConversionPattern<FuncOp> {
public:
  using QASMOpToPulseConversionPattern::QASMOpToPulseConversionPattern;
  LogicalResult
  matchAndRewrite(FuncOp funcOp, ArrayRef<Value> operands,
                  ConversionPatternRewriter &rewriter) const override {
    // generate converted function type
    TypeConverter::SignatureConversion inputs(funcOp.getNumArguments());
    size_t argIndex = 0;
    for (auto &en : llvm::enumerate(funcOp.getType().getInputs())) {
      Value qubitArg = en.value();

      if (en.value().isa<QASM::QubitType>()) {
        auto driveChannel = rewriter.getType<pulse::DriveChannel>();
        auto controlChannel = rewriter.getType<pulse::ControlChannel>();
        auto measureChannel = rewriter.getType<pulse::MeasureChannel>();
        auto acquireChannel = rewriter.getType<pulse::AcquireChannel>();

        inputs.addInputs(argIndex, driveChannel);
        inputs.addInputs(argIndex + 1, controlChannel);
        inputs.addInputs(argIndex + 2, measureChannel);
        inputs.addInputs(argIndex + 3, acquireChannel);

        std::vector<Value> channelValues = {
          rewriter.create<pulse::DriveChannelOp>(funcOp->getLoc()),
          rewriter.create<pulse::ControlChannelOp>(funcOp->getLoc()),
          rewriter.create<pulse::MeasureChannelOp>(funcOp->getLoc()),
          rewriter.create<pulse::AcquireChannelOp>(funcOp->getLoc())
        };

        qubitMap->setMapping(funcOp, qubitArg, channelValues);

        argIndex += 4;
      } else {
        inputs.addInputs(argIndex, typeConverter->convertType(qubitArg.getType()));

        argIndex++;
      }
    }

    auto funcType =
        FunctionType::get(funcOp->getContext(), inputs.getConvertedTypes(),
                          TypeRange{});

    // Generate the new FuncOp, and inline the body region
    auto newFuncOp =
        rewriter.create<FuncOp>(funcOp->getLoc(), funcOp.getName(), funcType);
    newFuncOp.setPrivate();

    rewriter.inlineRegionBefore(funcOp.getBody(), newFuncOp.getBody(),
                                newFuncOp.end());

    // Convert the signature and delete the original operation
    rewriter.applySignatureConversion(&newFuncOp.getBody(), inputs);
    rewriter.eraseOp(funcOp);

    return success();
  }
};

// /// Convert the return op for a qasm gate, returning the input qubits
// class ReturnOpConversion : public QASMOpToPulseConversionPattern<ReturnOp> {
// public:
//   using QASMOpToPulseConversionPattern::QASMOpToPulseConversionPattern;
//   LogicalResult
//   matchAndRewrite(ReturnOp returnOp, ArrayRef<Value> operands,
//                   ConversionPatternRewriter &rewriter) const override {
//     auto funcOp = returnOp->getParentOfType<FuncOp>();
//     auto qubits = qubitMap->flattenResults(funcOp);
//     rewriter.create<ReturnOp>(returnOp->getLoc(), qubits);
//     rewriter.eraseOp(returnOp);
//     return success();
//   }
// };

class CallOpConversion : public QASMOpToPulseConversionPattern<CallOp> {
public:
  using QASMOpToPulseConversionPattern::QASMOpToPulseConversionPattern;
  LogicalResult
  matchAndRewrite(CallOp callOp, ArrayRef<Value> operands,
                  ConversionPatternRewriter &rewriter) const override {
    auto parentFuncOp = callOp->getParentOfType<FuncOp>();

    SmallVector<Value> arguments, baseQubits;
    for (auto arg : operands) {
      if (arg.getType().isa<QASM::QubitType>()) {
        auto channels = qubitMap->resolveQubit(parentFuncOp, arg);
        auto driveChannel = channels[0];
        auto controlChannel = channels[1];
        auto measureChannel = channels[2];
        auto acquireChannel = channels[3];
        arguments.push_back(driveChannel);
        arguments.push_back(controlChannel);
        arguments.push_back(measureChannel);
        arguments.push_back(acquireChannel);
      } else {
        arguments.push_back(arg);
      }
    }

    // generate new call
    auto newCallOp = rewriter.create<CallOp>(
        callOp->getLoc(), callOp.getCallee(), TypeRange{}, arguments);
    rewriter.eraseOp(callOp);

    return success();
  }
};

class GateCallOpConversion
    : public QASMOpToPulseConversionPattern<QASM::GateCall> {
public:
  using QASMOpToPulseConversionPattern::QASMOpToPulseConversionPattern;
  LogicalResult
  matchAndRewrite(QASM::GateCall gateOp, ArrayRef<Value> operands,
                  ConversionPatternRewriter &rewriter) const override {
    auto func = op->getParentOfType<FuncOp>();
    Value dc0;
    Value alpha;
    for (auto arg : operands) {
      if (arg.getType().isa<QASM::QubitType>()) {
        auto channels = qubitMap->resolveQubit(func, arg);
        dc0 = channels[0];
      } else {
        alpha = arg;
      }
    }
    auto loc = op->getLoc();

    // currently supported: x, y, z, s, sdg, t, tdg, rx, ry, rz
    if (gateOp.gate_name() == "x") {
      auto dur = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(160));
      auto sigma = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(40));
      auto beta = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.7171287840008055));
      auto amp = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.1797336637124058));
      auto angle = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.0));
      auto wav = rewriter.create<pulse::DragOp>(loc, dur, sigma, beta, amp, angle);
      rewriter.create<pulse::PlayOp>(loc, wav, dc0);
    } else if (gateOp.gate_name() == "y") {
      auto pha = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(-3.1415926536));
      rewriter.create<pulse::ShiftPhaseOp>(loc, pha, dc0);
      auto dur = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(160));
      auto sigma = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(40));
      auto beta = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.7171287840008055));
      auto amp = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.1797336637124058));
      auto angle = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.0));
      auto wav = rewriter.create<pulse::DragOp>(loc, dur, sigma, beta, amp, angle);
      rewriter.create<pulse::PlayOp>(loc, wav, dc0);
    } else if (gateOp.gate_name() == "z") {
      auto pha = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(-3.1415926536));
      rewriter.create<pulse::ShiftPhaseOp>(loc, pha, dc0);
    } else if (gateOp.gate_name() == "h") {
      auto pha = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(-1.5707963268));
      rewriter.create<pulse::ShiftPhaseOp>(loc, pha, dc0);
      auto dur = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(160));
      auto sigma = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(40));
      auto beta = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.7190255528759942));
      auto amp = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.08981286442437861));
      auto angle = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(-0.003949372005175009));
      auto wav = rewriter.create<pulse::DragOp>(loc, dur, sigma, beta, amp, angle);
      rewriter.create<pulse::PlayOp>(loc, wav, dc0);
      rewriter.create<pulse::ShiftPhaseOp>(loc, pha, dc0);
    } else if (gateOp.gate_name() == "s") {
      auto pha = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(-1.5707963268));
      rewriter.create<pulse::ShiftPhaseOp>(loc, pha, dc0);
    } else if (gateOp.gate_name() == "sdg") {
      auto pha = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(1.5707963268));
      rewriter.create<pulse::ShiftPhaseOp>(loc, pha, dc0);
    } else if (gateOp.gate_name() == "t") {
      auto pha = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(-0.7853981634));
      rewriter.create<pulse::ShiftPhaseOp>(loc, pha, dc0);
    } else if (gateOp.gate_name() == "tdg") {
      auto pha = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.7853981634));
      rewriter.create<pulse::ShiftPhaseOp>(loc, pha, dc0);
    } else if (gateOp.gate_name() == "rx") {
      auto pha = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(-1.5707963268));
      rewriter.create<pulse::ShiftPhaseOp>(loc, pha, dc0);
      auto dur = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(160));
      auto sigma = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(40));
      auto beta = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.7190255528759942));
      auto amp = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.08981286442437861));
      auto angle = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(-0.003949372005175009));
      auto wav = rewriter.create<pulse::DragOp>(loc, dur, sigma, beta, amp, angle);
      rewriter.create<pulse::PlayOp>(loc, wav, dc0);
      auto tmp = rewriter.create<NegFOp>(loc, alpha);
      auto tmp1 = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(3.14159265358979));
      auto pha1 = rewriter.create<SubFOp>(loc, tmp, tmp1);
      rewriter.create<pulse::ShiftPhaseOp>(loc, pha1, dc0);
      rewriter.create<pulse::PlayOp>(loc, wav, dc0);
      auto pha2 = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(-7.853981634));
      rewriter.create<pulse::ShiftPhaseOp>(loc, pha2, dc0);
    } else if (gateOp.gate_name() == "ry") {
      auto pha = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.0));
      rewriter.create<pulse::ShiftPhaseOp>(loc, pha, dc0);
      auto dur = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(160));
      auto sigma = rewriter.create<ConstantOp>(loc, rewriter.getI32IntegerAttr(40));
      auto beta = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.7190255528759942));
      auto amp = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(0.08981286442437861));
      auto angle = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(-0.003949372005175009));
      auto wav = rewriter.create<pulse::DragOp>(loc, dur, sigma, beta, amp, angle);
      rewriter.create<pulse::PlayOp>(loc, wav, dc0);
      auto tmp = rewriter.create<NegFOp>(loc, alpha);
      auto tmp1 = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(3.14159265358979));
      auto pha1 = rewriter.create<SubFOp>(loc, tmp, tmp1);
      rewriter.create<pulse::ShiftPhaseOp>(loc, pha1, dc0);
      rewriter.create<pulse::PlayOp>(loc, wav, dc0);
      auto pha2 = rewriter.create<ConstantOp>(loc, rewriter.getF64FloatAttr(-9.4247779608));
      rewriter.create<pulse::ShiftPhaseOp>(loc, pha2, dc0);
    } else if (gateOp.gate_name() == "rz") {
      auto pha = rewriter.create<NegFOp>(loc, alpha);
      rewriter.create<pulse::ShiftPhaseOp>(loc, pha, dc0);
    } else {
      // generate new call
      emitWarning(gateOp->getLoc())
          << "Unknown gate call, converting to std.call instead";
      auto newCallOp = rewriter.create<CallOp>(
          gateOp->getLoc(), gateOp.gate_name(), resultTypes, arguments);
      resultQubits = newCallOp.getResults();
    }

    rewriter.eraseOp(gateOp);

    return success();
  }
};

// struct SCFIfConversion : QASMOpToQuantumConversionPattern<scf::IfOp> {
//   using QASMOpToQuantumConversionPattern::QASMOpToQuantumConversionPattern;
//   LogicalResult
//   matchAndRewrite(scf::IfOp ifOp, ArrayRef<Value> operands,
//                   ConversionPatternRewriter &rewriter) const override {
//     auto parentFuncOp = ifOp->getParentOfType<FuncOp>();

//     llvm::SmallVector<Value> qasmQubits, qssaQubits;
//     llvm::SmallVector<Type> yieldTypes;
//     // ASSUMPTION: EXACTLY one quantum operation in the thenRegion;
//     // elseRegion is empty.
//     for (auto &inst : ifOp.thenRegion().getBlocks().begin()->getOperations()) {
//       if (inst.hasTrait<OpTrait::IsTerminator>())
//         break;
//       for (auto arg : inst.getOperands()) {
//         if (arg.getType().isa<QASM::QubitType>()) {
//           qasmQubits.push_back(arg);
//           auto baseQubit = qubitMap->resolveQASMQubit(parentFuncOp, arg);
//           qssaQubits.push_back(baseQubit);
//           yieldTypes.push_back(getTypeConverter()->convertType(arg.getType()));
//         }
//       }
//     }

//     auto newIfOp =
//         rewriter.create<scf::IfOp>(ifOp->getLoc(), yieldTypes, ifOp.condition(),
//                                    /*withElseRegion=*/true);
//     auto pendingThenBuilder =
//         newIfOp.getThenBodyBuilder(rewriter.getListener());
//     auto elseBuilder = newIfOp.getElseBodyBuilder(); // do not listen/update
//     for (auto &inst : ifOp.thenRegion().getBlocks().begin()->getOperations()) {
//       if (inst.hasTrait<OpTrait::IsTerminator>()) {
//         pendingThenBuilder.create<scf::YieldOp>(inst.getLoc(), qssaQubits)
//             ->setAttr("qasm.if", rewriter.getUnitAttr());
//         SmallVector<Value> resolvedQubits(
//             llvm::map_range(qssaQubits, [&](Value v) {
//               return qubitMap->resolveQubit(parentFuncOp, v);
//             }));
//         elseBuilder.create<scf::YieldOp>(inst.getLoc(), resolvedQubits);
//       } else {
//         pendingThenBuilder.insert(inst.clone());
//       }
//     }

//     rewriter.eraseOp(ifOp);
//     return success();
//   }
// };

// struct SCFYieldConversion : QASMOpToPulseConversionPattern<scf::YieldOp> {
//   using QASMOpToPulseConversionPattern::QASMOpToPulseConversionPattern;
//   LogicalResult
//   matchAndRewrite(scf::YieldOp yieldOp, ArrayRef<Value> operands,
//                   ConversionPatternRewriter &rewriter) const final {
//     auto parentFuncOp = yieldOp->getParentOfType<FuncOp>();
//     auto ifOp = yieldOp->getParentOfType<scf::IfOp>();

//     SmallVector<Value> finalQubits;
//     for (auto argPair : llvm::zip(yieldOp.results(), ifOp.results())) {
//       Value baseQubit, resultQubit;
//       std::tie(baseQubit, resultQubit) = argPair;
//       finalQubits.push_back(qubitMap->resolveQubit(parentFuncOp, baseQubit));
//       qubitMap->updateQubit(parentFuncOp, baseQubit, resultQubit);
//     }
//     rewriter.create<scf::YieldOp>(yieldOp.getLoc(), finalQubits);
//     rewriter.eraseOp(yieldOp);
//     return success();
//   }
// };

void populateQASMToQuantumConversionPatterns(
    QASMTypeConverter &typeConverter, QubitMap &qubitMap,
    OwningRewritePatternList &patterns) {
  // clang-format off
  patterns.insert<
      FuncOpConversion,
      // ReturnOpConversion,
      CallOpConversion,
      GateCallOpConversion,
      AllocateOpConversion,
      MeasureOpConversion,
      ResetOpConversion,
      BarrierOpConversion,
      SingleQubitRotationOpConversion,
      ControlledNotOpConversion,
      // SCFIfConversion,
      // SCFYieldConversion
  >(typeConverter, &qubitMap);
  // clang-format on
}

struct QASMToPulseTarget : public ConversionTarget {
  QASMToPulseTarget(MLIRContext &ctx) : ConversionTarget(ctx) {
    addLegalDialect<StandardOpsDialect>();
    addLegalDialect<quantum::PulseDialect>();
    addLegalDialect<AffineDialect>();
    addLegalDialect<scf::SCFDialect>();

    addIllegalDialect<QASM::QASMDialect>();
    addDynamicallyLegalOp<FuncOp>(
        [&](FuncOp funcOp) -> bool { return !funcOp->hasAttr("qasm.gate"); });
    addDynamicallyLegalOp<CallOp>(
        [&](CallOp callOp) -> bool { return !callOp->hasAttr("qasm.gate"); });
    addDynamicallyLegalOp<ReturnOp>(
        [&](ReturnOp returnOp) { return !returnOp->hasAttr("qasm.gate_end"); });
      addDynamicallyLegalOp<scf::IfOp>(
        [&](scf::IfOp op) { return true; });
    addDynamicallyLegalOp<scf::YieldOp>(
        [&](scf::YieldOp op) { return true; });
    // addDynamicallyLegalOp<scf::IfOp>(
    //     [&](scf::IfOp op) { return !op->hasAttr("qasm.if"); });
    // addDynamicallyLegalOp<scf::YieldOp>(
    //     [&](scf::YieldOp op) { return !op->hasAttr("qasm.if"); });
  }
};

struct QASMToPulsePass : public QASMToPulsePassBase<QASMToPulsePass> {
  void runOnOperation() override;
};

void QASMToPulsePass::runOnOperation() {
  OwningRewritePatternList patterns(&getContext());
  QASMTypeConverter typeConverter(&getContext());
  QubitMap qubitMap(&getContext());
  populateQASMToPulseConversionPatterns(typeConverter, qubitMap, patterns);

  QASMToPulseTarget target(getContext());
  if (failed(applyPartialConversion(getOperation(), target,
                                    std::move(patterns)))) {
    return signalPassFailure();
  }
}
} // namespace

namespace mlir {
std::unique_ptr<Pass> createQASMToPulsePass() {
  return std::make_unique<QASMToPulsePass>();
}
} // namespace mlir
