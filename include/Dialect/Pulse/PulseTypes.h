/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* TypeDef Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_TYPEDEF_CLASSES
#undef GET_TYPEDEF_CLASSES


namespace mlir {
class DialectAsmParser;
class DialectAsmPrinter;
} // namespace mlir
namespace mlir {
namespace pulse {
  class AcquireChannelType;
  class ActionType;
  class ControlChannelType;
  class DriveChannelType;
  class MeasureChannelType;
  class MemorySlotType;
  class WaveformType;

  class AcquireChannelType : public ::mlir::Type::TypeBase<AcquireChannelType, ::mlir::Type, ::mlir::TypeStorage> {
  public:
    /// Inherit some necessary constructors from 'TypeBase'.
    using Base::Base;
    static constexpr ::llvm::StringLiteral getMnemonic() {
      return ::llvm::StringLiteral("acquire_channel");
    }
  };

  class ActionType : public ::mlir::Type::TypeBase<ActionType, ::mlir::Type, ::mlir::TypeStorage> {
  public:
    /// Inherit some necessary constructors from 'TypeBase'.
    using Base::Base;
    static constexpr ::llvm::StringLiteral getMnemonic() {
      return ::llvm::StringLiteral("action");
    }
  };

  class ControlChannelType : public ::mlir::Type::TypeBase<ControlChannelType, ::mlir::Type, ::mlir::TypeStorage> {
  public:
    /// Inherit some necessary constructors from 'TypeBase'.
    using Base::Base;
    static constexpr ::llvm::StringLiteral getMnemonic() {
      return ::llvm::StringLiteral("control_channel");
    }
  };

  class DriveChannelType : public ::mlir::Type::TypeBase<DriveChannelType, ::mlir::Type, ::mlir::TypeStorage> {
  public:
    /// Inherit some necessary constructors from 'TypeBase'.
    using Base::Base;
    static constexpr ::llvm::StringLiteral getMnemonic() {
      return ::llvm::StringLiteral("drive_channel");
    }
  };

  class MeasureChannelType : public ::mlir::Type::TypeBase<MeasureChannelType, ::mlir::Type, ::mlir::TypeStorage> {
  public:
    /// Inherit some necessary constructors from 'TypeBase'.
    using Base::Base;
    static constexpr ::llvm::StringLiteral getMnemonic() {
      return ::llvm::StringLiteral("measure_channel");
    }
  };

  class MemorySlotType : public ::mlir::Type::TypeBase<MemorySlotType, ::mlir::Type, ::mlir::TypeStorage> {
  public:
    /// Inherit some necessary constructors from 'TypeBase'.
    using Base::Base;
    static constexpr ::llvm::StringLiteral getMnemonic() {
      return ::llvm::StringLiteral("memory_slot");
    }
  };

  class WaveformType : public ::mlir::Type::TypeBase<WaveformType, ::mlir::Type, ::mlir::TypeStorage> {
  public:
    /// Inherit some necessary constructors from 'TypeBase'.
    using Base::Base;
    static constexpr ::llvm::StringLiteral getMnemonic() {
      return ::llvm::StringLiteral("waveform");
    }
  };
} // namespace pulse
} // namespace mlir

#endif  // GET_TYPEDEF_CLASSES

