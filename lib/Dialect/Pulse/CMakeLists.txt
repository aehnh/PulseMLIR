add_mlir_dialect_library(MLIRPulse
  PulseDialect.cpp
  PulseTypes.cpp
  PulseOps.cpp

  ADDITIONAL_HEADER_DIRS
  ${PROJECT_SOURCE_DIR}/include/Dialect/Pulse

  DEPENDS
  MLIRPulseOpsIncGen

  LINK_LIBS PUBLIC
  MLIRIR
)
