#ifndef PULSE_PULSETYPES_H
#define PULSE_PULSETYPES_H

#include "mlir/IR/AttributeSupport.h"
#include "mlir/IR/Attributes.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/TypeSupport.h"
#include "mlir/IR/Types.h"

#define GET_TYPEDEF_CLASSES
#include "Dialect/Pulse/PulseOpsTypes.h.inc"

#endif // PULSE_PULSETYPES_H
