#include "mlir/IR/DialectImplementation.h"
#include "mlir/IR/Types.h"
#include "mlir/Support/LLVM.h"
#include "mlir/Support/LogicalResult.h"
#include "mlir/Transforms/InliningUtils.h"

#include "Dialect/Pulse/PulseDialect.h"
#include "Dialect/Pulse/PulseOps.h"
#include "Dialect/Pulse/PulseTypes.h"

using namespace mlir;
using namespace mlir::pulse;

namespace {
/// This class defines the interface for handling inlining with qssa
/// operations.
struct PulseInlinerInterface : public DialectInlinerInterface {
  using DialectInlinerInterface::DialectInlinerInterface;

  /// All operations within math ops can be inlined.
  bool isLegalToInline(Operation *, Region *, bool,
                       BlockAndValueMapping &) const final {
    return true;
  }
  bool isLegalToInline(Region *dest, Region *src, bool,
                       BlockAndValueMapping &) const final {
    return true;
  }
};
} // end anonymous namespace

void PulseDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "Dialect/Pulse/PulseOps.cpp.inc"
      >();
  addTypes<
#define GET_TYPEDEF_LIST
#include "Dialect/Pulse/PulseOpsTypes.cpp.inc"
      >();
  addInterfaces<PulseInlinerInterface>();
}

Operation *PulseDialect::materializeConstant(OpBuilder &builder, Attribute value,
                                            Type type, Location loc) {
  return builder.create<ConstantOp>(loc, type, value);
}
