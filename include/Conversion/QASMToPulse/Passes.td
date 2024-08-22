#ifndef CONVERSION_QASMTOPULSE_PASSES_TD
#define CONVERSION_QASMTOPULSE_PASSES_TD

include "mlir/Pass/PassBase.td"

def QASMToPulsePass : Pass<"convert-qasm-to-pulse", "ModuleOp"> {
  let summary = "Convert QASM dialect to pulse dialect";
  let constructor = "mlir::createQASMToPulsePass()";
  let dependentDialects = ["QASM::QASMDialect",
                           "pulse::PulseDialect",
                           "StandardOpsDialect",
                           "AffineDialect",
                           "scf::SCFDialect",
                           "ArithDialect"];
}

#endif // CONVERSION_QASMTOPULSE_PASSES_TD
