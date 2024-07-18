/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Declarations                                                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#if defined(GET_OP_CLASSES) || defined(GET_OP_FWD_DEFINES)
#undef GET_OP_FWD_DEFINES
namespace mlir {
namespace pulse {
class AcquireOp;
} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {
class DelayOp;
} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {
class DragOp;
} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {
class GaussianSquareOp;
} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {
class InitializeChannelsOp;
} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {
class InitializeMemorySlotOp;
} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {
class PlayOp;
} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {
class ScheduleOp;
} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {
class ShiftPhaseOp;
} // namespace pulse
} // namespace mlir
#endif

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES

namespace mlir {
namespace pulse {

//===----------------------------------------------------------------------===//
// ::mlir::pulse::AcquireOp declarations
//===----------------------------------------------------------------------===//

class AcquireOpAdaptor {
public:
  AcquireOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});
  AcquireOpAdaptor(AcquireOp&op);
  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value dur();
  ::mlir::Value cha();
  ::mlir::Value mem();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);

private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
};
class AcquireOp : public ::mlir::Op<AcquireOp, ::mlir::OpTrait::ZeroRegion, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::pulse::ActionType>::Impl, ::mlir::OpTrait::ZeroSuccessor, ::mlir::OpTrait::NOperands<3>::Impl> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = AcquireOpAdaptor;
  static constexpr ::llvm::StringLiteral getOperationName() {
  return ::llvm::StringLiteral("pulse.acquire");
}
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value dur();
  ::mlir::Value cha();
  ::mlir::Value mem();
  ::mlir::MutableOperandRange durMutable();
  ::mlir::MutableOperandRange chaMutable();
  ::mlir::MutableOperandRange memMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value act();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type act, ::mlir::Value dur, ::mlir::Value cha, ::mlir::Value mem);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value dur, ::mlir::Value cha, ::mlir::Value mem);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &p);
};
} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {

//===----------------------------------------------------------------------===//
// ::mlir::pulse::DelayOp declarations
//===----------------------------------------------------------------------===//

class DelayOpAdaptor {
public:
  DelayOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});
  DelayOpAdaptor(DelayOp&op);
  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value dur();
  ::mlir::Value cha();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);

private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
};
class DelayOp : public ::mlir::Op<DelayOp, ::mlir::OpTrait::ZeroRegion, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::pulse::ActionType>::Impl, ::mlir::OpTrait::ZeroSuccessor, ::mlir::OpTrait::NOperands<2>::Impl> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = DelayOpAdaptor;
  static constexpr ::llvm::StringLiteral getOperationName() {
  return ::llvm::StringLiteral("pulse.delay");
}
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value dur();
  ::mlir::Value cha();
  ::mlir::MutableOperandRange durMutable();
  ::mlir::MutableOperandRange chaMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value act();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type act, ::mlir::Value dur, ::mlir::Value cha);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value dur, ::mlir::Value cha);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &p);
};
} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {

//===----------------------------------------------------------------------===//
// ::mlir::pulse::DragOp declarations
//===----------------------------------------------------------------------===//

class DragOpAdaptor {
public:
  DragOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});
  DragOpAdaptor(DragOp&op);
  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value dur();
  ::mlir::Value sig();
  ::mlir::Value beta();
  ::mlir::Value amp();
  ::mlir::Value angle();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);

private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
};
class DragOp : public ::mlir::Op<DragOp, ::mlir::OpTrait::ZeroRegion, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::pulse::WaveformType>::Impl, ::mlir::OpTrait::ZeroSuccessor, ::mlir::OpTrait::NOperands<5>::Impl> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = DragOpAdaptor;
  static constexpr ::llvm::StringLiteral getOperationName() {
  return ::llvm::StringLiteral("pulse.drag");
}
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value dur();
  ::mlir::Value sig();
  ::mlir::Value beta();
  ::mlir::Value amp();
  ::mlir::Value angle();
  ::mlir::MutableOperandRange durMutable();
  ::mlir::MutableOperandRange sigMutable();
  ::mlir::MutableOperandRange betaMutable();
  ::mlir::MutableOperandRange ampMutable();
  ::mlir::MutableOperandRange angleMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value wav();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type wav, ::mlir::Value dur, ::mlir::Value sig, ::mlir::Value beta, ::mlir::Value amp, ::mlir::Value angle);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value dur, ::mlir::Value sig, ::mlir::Value beta, ::mlir::Value amp, ::mlir::Value angle);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &p);
};
} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {

//===----------------------------------------------------------------------===//
// ::mlir::pulse::GaussianSquareOp declarations
//===----------------------------------------------------------------------===//

class GaussianSquareOpAdaptor {
public:
  GaussianSquareOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});
  GaussianSquareOpAdaptor(GaussianSquareOp&op);
  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value dur();
  ::mlir::Value sig();
  ::mlir::Value width();
  ::mlir::Value amp();
  ::mlir::Value angle();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);

private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
};
class GaussianSquareOp : public ::mlir::Op<GaussianSquareOp, ::mlir::OpTrait::ZeroRegion, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::pulse::WaveformType>::Impl, ::mlir::OpTrait::ZeroSuccessor, ::mlir::OpTrait::NOperands<5>::Impl> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = GaussianSquareOpAdaptor;
  static constexpr ::llvm::StringLiteral getOperationName() {
  return ::llvm::StringLiteral("pulse.gaussian_square");
}
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value dur();
  ::mlir::Value sig();
  ::mlir::Value width();
  ::mlir::Value amp();
  ::mlir::Value angle();
  ::mlir::MutableOperandRange durMutable();
  ::mlir::MutableOperandRange sigMutable();
  ::mlir::MutableOperandRange widthMutable();
  ::mlir::MutableOperandRange ampMutable();
  ::mlir::MutableOperandRange angleMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value wav();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type wav, ::mlir::Value dur, ::mlir::Value sig, ::mlir::Value width, ::mlir::Value amp, ::mlir::Value angle);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value dur, ::mlir::Value sig, ::mlir::Value width, ::mlir::Value amp, ::mlir::Value angle);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &p);
};
} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {

//===----------------------------------------------------------------------===//
// ::mlir::pulse::InitializeChannelsOp declarations
//===----------------------------------------------------------------------===//

class InitializeChannelsOpAdaptor {
public:
  InitializeChannelsOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});
  InitializeChannelsOpAdaptor(InitializeChannelsOp&op);
  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);

private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
};
class InitializeChannelsOp : public ::mlir::Op<InitializeChannelsOp, ::mlir::OpTrait::ZeroRegion, ::mlir::OpTrait::NResults<4>::Impl, ::mlir::OpTrait::ZeroSuccessor, ::mlir::OpTrait::ZeroOperands, ::mlir::OpAsmOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = InitializeChannelsOpAdaptor;
  void getAsmResultNames(::mlir::OpAsmSetValueNameFn setNameFn);
  static constexpr ::llvm::StringLiteral getOperationName() {
  return ::llvm::StringLiteral("pulse.initialize_channels");
}
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value dc();
  ::mlir::Value cc();
  ::mlir::Value mc();
  ::mlir::Value ac();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type dc, ::mlir::Type cc, ::mlir::Type mc, ::mlir::Type ac);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &p);
};
} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {

//===----------------------------------------------------------------------===//
// ::mlir::pulse::InitializeMemorySlotOp declarations
//===----------------------------------------------------------------------===//

class InitializeMemorySlotOpAdaptor {
public:
  InitializeMemorySlotOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});
  InitializeMemorySlotOpAdaptor(InitializeMemorySlotOp&op);
  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);

private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
};
class InitializeMemorySlotOp : public ::mlir::Op<InitializeMemorySlotOp, ::mlir::OpTrait::ZeroRegion, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::pulse::MemorySlotType>::Impl, ::mlir::OpTrait::ZeroSuccessor, ::mlir::OpTrait::ZeroOperands> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = InitializeMemorySlotOpAdaptor;
  static constexpr ::llvm::StringLiteral getOperationName() {
  return ::llvm::StringLiteral("pulse.initialize_memory_slot");
}
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value ms();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type ms);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &p);
};
} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {

//===----------------------------------------------------------------------===//
// ::mlir::pulse::PlayOp declarations
//===----------------------------------------------------------------------===//

class PlayOpAdaptor {
public:
  PlayOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});
  PlayOpAdaptor(PlayOp&op);
  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value wav();
  ::mlir::Value cha();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);

private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
};
class PlayOp : public ::mlir::Op<PlayOp, ::mlir::OpTrait::ZeroRegion, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::pulse::ActionType>::Impl, ::mlir::OpTrait::ZeroSuccessor, ::mlir::OpTrait::NOperands<2>::Impl> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = PlayOpAdaptor;
  static constexpr ::llvm::StringLiteral getOperationName() {
  return ::llvm::StringLiteral("pulse.play");
}
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value wav();
  ::mlir::Value cha();
  ::mlir::MutableOperandRange wavMutable();
  ::mlir::MutableOperandRange chaMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value act();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type act, ::mlir::Value wav, ::mlir::Value cha);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value wav, ::mlir::Value cha);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &p);
};
} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {

//===----------------------------------------------------------------------===//
// ::mlir::pulse::ScheduleOp declarations
//===----------------------------------------------------------------------===//

class ScheduleOpAdaptor {
public:
  ScheduleOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});
  ScheduleOpAdaptor(ScheduleOp&op);
  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value time();
  ::mlir::Value act();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);

private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
};
class ScheduleOp : public ::mlir::Op<ScheduleOp, ::mlir::OpTrait::ZeroRegion, ::mlir::OpTrait::ZeroResult, ::mlir::OpTrait::ZeroSuccessor, ::mlir::OpTrait::NOperands<2>::Impl> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ScheduleOpAdaptor;
  static constexpr ::llvm::StringLiteral getOperationName() {
  return ::llvm::StringLiteral("pulse.schedule");
}
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value time();
  ::mlir::Value act();
  ::mlir::MutableOperandRange timeMutable();
  ::mlir::MutableOperandRange actMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value time, ::mlir::Value act);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value time, ::mlir::Value act);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &p);
};
} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {

//===----------------------------------------------------------------------===//
// ::mlir::pulse::ShiftPhaseOp declarations
//===----------------------------------------------------------------------===//

class ShiftPhaseOpAdaptor {
public:
  ShiftPhaseOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});
  ShiftPhaseOpAdaptor(ShiftPhaseOp&op);
  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value phase();
  ::mlir::Value cha();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);

private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
};
class ShiftPhaseOp : public ::mlir::Op<ShiftPhaseOp, ::mlir::OpTrait::ZeroRegion, ::mlir::OpTrait::ZeroResult, ::mlir::OpTrait::ZeroSuccessor, ::mlir::OpTrait::NOperands<2>::Impl> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ShiftPhaseOpAdaptor;
  static constexpr ::llvm::StringLiteral getOperationName() {
  return ::llvm::StringLiteral("pulse.shift_phase");
}
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value phase();
  ::mlir::Value cha();
  ::mlir::MutableOperandRange phaseMutable();
  ::mlir::MutableOperandRange chaMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value phase, ::mlir::Value cha);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value phase, ::mlir::Value cha);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &p);
};
} // namespace pulse
} // namespace mlir

#endif  // GET_OP_CLASSES

