#ifndef CONVERSION_QASMTOPULSE_PASSES_H
#define CONVERSION_QASMTOPULSE_PASSES_H

#include "mlir/Pass/Pass.h"

namespace mlir {

class Pass;

std::unique_ptr<Pass> createQASMToPulsePass();

#define GEN_PASS_REGISTRATION
#include "Conversion/QASMToPulse/Passes.h.inc"

} // namespace mlir

#endif // CONVERSION_QASMTOPULSE_PASSES_H
