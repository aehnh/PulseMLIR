#include "mlir/IR/DialectImplementation.h"
#include "llvm/ADT/TypeSwitch.h"

#include "Dialect/Pulse/PulseDialect.h"
#include "Dialect/Pulse/PulseTypes.h"

#define GET_TYPEDEF_CLASSES
#include "Dialect/Pulse/PulseOpsTypes.cpp.inc"

using namespace mlir;
using namespace mlir::pulse;

Type PulseDialect::parseType(DialectAsmParser &parser) const {
  StringRef mnemonic;
  if (failed(parser.parseKeyword(&mnemonic)))
    return Type();
  Type type;
  generatedTypeParser(getContext(), parser, mnemonic, type);
  return type;
}

/// Print a type registered to this dialect.
void PulseDialect::printType(Type type, DialectAsmPrinter &os) const {
  (void)generatedTypePrinter(type, os);
}
