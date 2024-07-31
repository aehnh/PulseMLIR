#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/SCF/SCF.h"
#include "mlir/Dialect/StandardOps/IR/Ops.h"
#include "mlir/Transforms/DialectConversion.h"

#include "Conversion/QASMToQuantum/Passes.h"
#include "Dialect/QASM/QASMDialect.h"
#include "Dialect/QASM/QASMOps.h"
#include "Dialect/Pulse/PulseDialect.h"
#include "Dialect/Pulse/PulseOps.h"
#include "PassDetail.h"

using namespace mlir;


