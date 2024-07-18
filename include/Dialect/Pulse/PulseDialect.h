/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace pulse {

class PulseDialect : public ::mlir::Dialect {
  explicit PulseDialect(::mlir::MLIRContext *context)
    : ::mlir::Dialect(getDialectNamespace(), context,
      ::mlir::TypeID::get<PulseDialect>()) {
    
    initialize();
  }
  void initialize();
  friend class ::mlir::MLIRContext;
public:
  static constexpr ::llvm::StringLiteral getDialectNamespace() {
    return ::llvm::StringLiteral("pulse");
  }
};
} // namespace pulse
} // namespace mlir
