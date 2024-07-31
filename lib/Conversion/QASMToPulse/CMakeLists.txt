add_mlir_dialect_library(QASMToPulse
  ConvertQASMToPulse.cpp

  ADDITIONAL_HEADER_DIRS
  ${PROJECT_SOURCE_DIR}/include/Conversion/QASMToPulse

  DEPENDS
  MLIRQASMToPulsePassIncGen
)

target_link_libraries(QASMToPulse PUBLIC MLIRIR)
