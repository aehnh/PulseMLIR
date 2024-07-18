/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* TypeDef Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_TYPEDEF_LIST
#undef GET_TYPEDEF_LIST

::mlir::pulse::AcquireChannelType,
::mlir::pulse::ActionType,
::mlir::pulse::ControlChannelType,
::mlir::pulse::DriveChannelType,
::mlir::pulse::MeasureChannelType,
::mlir::pulse::MemorySlotType,
::mlir::pulse::WaveformType

#endif  // GET_TYPEDEF_LIST

#ifdef GET_TYPEDEF_CLASSES
#undef GET_TYPEDEF_CLASSES


static ::mlir::OptionalParseResult generatedTypeParser(::mlir::MLIRContext *context,
                                      ::mlir::DialectAsmParser &parser,
                                      ::llvm::StringRef mnemonic,
                                      ::mlir::Type &value) {
  if (mnemonic == ::mlir::pulse::AcquireChannelType::getMnemonic()) { 
    value = ::mlir::pulse::AcquireChannelType::get(context);
    return ::mlir::success(!!value);
  }
  if (mnemonic == ::mlir::pulse::ActionType::getMnemonic()) { 
    value = ::mlir::pulse::ActionType::get(context);
    return ::mlir::success(!!value);
  }
  if (mnemonic == ::mlir::pulse::ControlChannelType::getMnemonic()) { 
    value = ::mlir::pulse::ControlChannelType::get(context);
    return ::mlir::success(!!value);
  }
  if (mnemonic == ::mlir::pulse::DriveChannelType::getMnemonic()) { 
    value = ::mlir::pulse::DriveChannelType::get(context);
    return ::mlir::success(!!value);
  }
  if (mnemonic == ::mlir::pulse::MeasureChannelType::getMnemonic()) { 
    value = ::mlir::pulse::MeasureChannelType::get(context);
    return ::mlir::success(!!value);
  }
  if (mnemonic == ::mlir::pulse::MemorySlotType::getMnemonic()) { 
    value = ::mlir::pulse::MemorySlotType::get(context);
    return ::mlir::success(!!value);
  }
  if (mnemonic == ::mlir::pulse::WaveformType::getMnemonic()) { 
    value = ::mlir::pulse::WaveformType::get(context);
    return ::mlir::success(!!value);
  }
  return {};
}


static ::mlir::LogicalResult generatedTypePrinter(
                         ::mlir::Type def, ::mlir::DialectAsmPrinter &printer) {
  return ::llvm::TypeSwitch<::mlir::Type, ::mlir::LogicalResult>(def)
    .Case<::mlir::pulse::AcquireChannelType>([&](::mlir::pulse::AcquireChannelType t) {
      printer << ::mlir::pulse::AcquireChannelType::getMnemonic();
      return ::mlir::success();
    })
    .Case<::mlir::pulse::ActionType>([&](::mlir::pulse::ActionType t) {
      printer << ::mlir::pulse::ActionType::getMnemonic();
      return ::mlir::success();
    })
    .Case<::mlir::pulse::ControlChannelType>([&](::mlir::pulse::ControlChannelType t) {
      printer << ::mlir::pulse::ControlChannelType::getMnemonic();
      return ::mlir::success();
    })
    .Case<::mlir::pulse::DriveChannelType>([&](::mlir::pulse::DriveChannelType t) {
      printer << ::mlir::pulse::DriveChannelType::getMnemonic();
      return ::mlir::success();
    })
    .Case<::mlir::pulse::MeasureChannelType>([&](::mlir::pulse::MeasureChannelType t) {
      printer << ::mlir::pulse::MeasureChannelType::getMnemonic();
      return ::mlir::success();
    })
    .Case<::mlir::pulse::MemorySlotType>([&](::mlir::pulse::MemorySlotType t) {
      printer << ::mlir::pulse::MemorySlotType::getMnemonic();
      return ::mlir::success();
    })
    .Case<::mlir::pulse::WaveformType>([&](::mlir::pulse::WaveformType t) {
      printer << ::mlir::pulse::WaveformType::getMnemonic();
      return ::mlir::success();
    })
    .Default([](::mlir::Type) { return ::mlir::failure(); });
}

namespace mlir {
namespace pulse {
} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {
} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {
} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {
} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {
} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {
} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {
} // namespace pulse
} // namespace mlir

#endif  // GET_TYPEDEF_CLASSES

