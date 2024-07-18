/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Definitions                                                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_OP_LIST
#undef GET_OP_LIST

::mlir::pulse::AcquireOp,
::mlir::pulse::DelayOp,
::mlir::pulse::DragOp,
::mlir::pulse::GaussianSquareOp,
::mlir::pulse::InitializeChannelsOp,
::mlir::pulse::InitializeMemorySlotOp,
::mlir::pulse::PlayOp,
::mlir::pulse::ScheduleOp,
::mlir::pulse::ShiftPhaseOp
#endif  // GET_OP_LIST

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//

namespace mlir {
namespace pulse {
static ::mlir::LogicalResult __mlir_ods_local_type_constraint_PulseOps0(::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind, unsigned valueGroupStartIndex) {
  if (!((type.isa<::mlir::IntegerType>()))) {
    return op->emitOpError(valueKind) << " #" << valueGroupStartIndex << " must be integer, but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_PulseOps1(::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind, unsigned valueGroupStartIndex) {
  if (!(((type.isa<::mlir::pulse::DriveChannelType>())) || ((type.isa<::mlir::pulse::ControlChannelType>())) || ((type.isa<::mlir::pulse::MeasureChannelType>())))) {
    return op->emitOpError(valueKind) << " #" << valueGroupStartIndex << " must be  or  or , but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_PulseOps2(::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind, unsigned valueGroupStartIndex) {
  if (!((type.isa<::mlir::pulse::MemorySlotType>()))) {
    return op->emitOpError(valueKind) << " #" << valueGroupStartIndex << " must be , but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_PulseOps3(::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind, unsigned valueGroupStartIndex) {
  if (!((type.isa<::mlir::pulse::ActionType>()))) {
    return op->emitOpError(valueKind) << " #" << valueGroupStartIndex << " must be , but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_PulseOps4(::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind, unsigned valueGroupStartIndex) {
  if (!((type.isa<::mlir::FloatType>()))) {
    return op->emitOpError(valueKind) << " #" << valueGroupStartIndex << " must be floating-point, but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_PulseOps5(::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind, unsigned valueGroupStartIndex) {
  if (!((type.isa<::mlir::ComplexType>()))) {
    return op->emitOpError(valueKind) << " #" << valueGroupStartIndex << " must be complex-type, but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_PulseOps6(::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind, unsigned valueGroupStartIndex) {
  if (!((type.isa<::mlir::pulse::WaveformType>()))) {
    return op->emitOpError(valueKind) << " #" << valueGroupStartIndex << " must be , but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_PulseOps7(::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind, unsigned valueGroupStartIndex) {
  if (!((type.isa<::mlir::pulse::DriveChannelType>()))) {
    return op->emitOpError(valueKind) << " #" << valueGroupStartIndex << " must be , but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_PulseOps8(::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind, unsigned valueGroupStartIndex) {
  if (!((type.isa<::mlir::pulse::ControlChannelType>()))) {
    return op->emitOpError(valueKind) << " #" << valueGroupStartIndex << " must be , but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_PulseOps9(::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind, unsigned valueGroupStartIndex) {
  if (!((type.isa<::mlir::pulse::MeasureChannelType>()))) {
    return op->emitOpError(valueKind) << " #" << valueGroupStartIndex << " must be , but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_PulseOps10(::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind, unsigned valueGroupStartIndex) {
  if (!((type.isa<::mlir::pulse::AcquireChannelType>()))) {
    return op->emitOpError(valueKind) << " #" << valueGroupStartIndex << " must be , but got " << type;
  }
  return ::mlir::success();
}

} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {

//===----------------------------------------------------------------------===//
// ::mlir::pulse::AcquireOp definitions
//===----------------------------------------------------------------------===//

AcquireOpAdaptor::AcquireOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs, ::mlir::RegionRange regions)  : odsOperands(values), odsAttrs(attrs), odsRegions(regions) {

}

AcquireOpAdaptor::AcquireOpAdaptor(AcquireOp&op)  : odsOperands(op->getOperands()), odsAttrs(op->getAttrDictionary()), odsRegions(op->getRegions()) {

}

::mlir::ValueRange AcquireOpAdaptor::getOperands() {
  return odsOperands;
}

std::pair<unsigned, unsigned> AcquireOpAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::ValueRange AcquireOpAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

::mlir::Value AcquireOpAdaptor::dur() {
  return *getODSOperands(0).begin();
}

::mlir::Value AcquireOpAdaptor::cha() {
  return *getODSOperands(1).begin();
}

::mlir::Value AcquireOpAdaptor::mem() {
  return *getODSOperands(2).begin();
}

::mlir::DictionaryAttr AcquireOpAdaptor::getAttributes() {
  return odsAttrs;
}

::mlir::LogicalResult AcquireOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}



std::pair<unsigned, unsigned> AcquireOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range AcquireOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value AcquireOp::dur() {
  return *getODSOperands(0).begin();
}

::mlir::Value AcquireOp::cha() {
  return *getODSOperands(1).begin();
}

::mlir::Value AcquireOp::mem() {
  return *getODSOperands(2).begin();
}

::mlir::MutableOperandRange AcquireOp::durMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

::mlir::MutableOperandRange AcquireOp::chaMutable() {
  auto range = getODSOperandIndexAndLength(1);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

::mlir::MutableOperandRange AcquireOp::memMutable() {
  auto range = getODSOperandIndexAndLength(2);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> AcquireOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range AcquireOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value AcquireOp::act() {
  return *getODSResults(0).begin();
}

void AcquireOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type act, ::mlir::Value dur, ::mlir::Value cha, ::mlir::Value mem) {
  odsState.addOperands(dur);
  odsState.addOperands(cha);
  odsState.addOperands(mem);
  odsState.addTypes(act);
}

void AcquireOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value dur, ::mlir::Value cha, ::mlir::Value mem) {
  odsState.addOperands(dur);
  odsState.addOperands(cha);
  odsState.addOperands(mem);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void AcquireOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 3u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult AcquireOp::verify() {
  if (failed(AcquireOpAdaptor(*this).verify((*this)->getLoc()))) return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps0(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
    auto valueGroup1 = getODSOperands(1);
    for (::mlir::Value v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps1(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
    auto valueGroup2 = getODSOperands(2);
    for (::mlir::Value v : valueGroup2) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps2(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps3(getOperation(), v.getType(), "result", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  return ::mlir::success();
}

::mlir::ParseResult AcquireOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::OperandType durRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::OperandType> durOperands(durRawOperands);  ::llvm::SMLoc durOperandsLoc;
  (void)durOperandsLoc;
  ::mlir::OpAsmParser::OperandType chaRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::OperandType> chaOperands(chaRawOperands);  ::llvm::SMLoc chaOperandsLoc;
  (void)chaOperandsLoc;
  ::mlir::OpAsmParser::OperandType memRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::OperandType> memOperands(memRawOperands);  ::llvm::SMLoc memOperandsLoc;
  (void)memOperandsLoc;
  ::mlir::Type durRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> durTypes(durRawTypes);
  ::mlir::Type chaRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> chaTypes(chaRawTypes);
  ::mlir::Type memRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> memTypes(memRawTypes);
  ::mlir::Type actRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> actTypes(actRawTypes);
  if (parser.parseOptionalAttrDict(result.attributes))
    return ::mlir::failure();
  if (parser.parseLParen())
    return ::mlir::failure();

  durOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(durRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  chaOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(chaRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  memOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(memRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  if (parser.parseColon())
    return ::mlir::failure();
  if (parser.parseLParen())
    return ::mlir::failure();

  if (parser.parseType(durRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  if (parser.parseType(chaRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  if (parser.parseType(memRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  if (parser.parseArrow())
    return ::mlir::failure();

  if (parser.parseType(actRawTypes[0]))
    return ::mlir::failure();
  result.addTypes(actTypes);
  if (parser.resolveOperands(durOperands, durTypes, durOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(chaOperands, chaTypes, chaOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(memOperands, memTypes, memOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void AcquireOp::print(::mlir::OpAsmPrinter &p) {
  p << "pulse.acquire";
  p.printOptionalAttrDict((*this)->getAttrs(), /*elidedAttrs=*/{});
  p << "(";
  p << dur();
  p << ",";
  p << ' ';
  p << cha();
  p << ",";
  p << ' ';
  p << mem();
  p << ")";
  p << ' ' << ":";
  p << ' ' << "(";
  p << ::llvm::ArrayRef<::mlir::Type>(dur().getType());
  p << ",";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(cha().getType());
  p << ",";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(mem().getType());
  p << ")";
  p << ' ' << "->";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(act().getType());
}

} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {

//===----------------------------------------------------------------------===//
// ::mlir::pulse::DelayOp definitions
//===----------------------------------------------------------------------===//

DelayOpAdaptor::DelayOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs, ::mlir::RegionRange regions)  : odsOperands(values), odsAttrs(attrs), odsRegions(regions) {

}

DelayOpAdaptor::DelayOpAdaptor(DelayOp&op)  : odsOperands(op->getOperands()), odsAttrs(op->getAttrDictionary()), odsRegions(op->getRegions()) {

}

::mlir::ValueRange DelayOpAdaptor::getOperands() {
  return odsOperands;
}

std::pair<unsigned, unsigned> DelayOpAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::ValueRange DelayOpAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

::mlir::Value DelayOpAdaptor::dur() {
  return *getODSOperands(0).begin();
}

::mlir::Value DelayOpAdaptor::cha() {
  return *getODSOperands(1).begin();
}

::mlir::DictionaryAttr DelayOpAdaptor::getAttributes() {
  return odsAttrs;
}

::mlir::LogicalResult DelayOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}



std::pair<unsigned, unsigned> DelayOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range DelayOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value DelayOp::dur() {
  return *getODSOperands(0).begin();
}

::mlir::Value DelayOp::cha() {
  return *getODSOperands(1).begin();
}

::mlir::MutableOperandRange DelayOp::durMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

::mlir::MutableOperandRange DelayOp::chaMutable() {
  auto range = getODSOperandIndexAndLength(1);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> DelayOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range DelayOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value DelayOp::act() {
  return *getODSResults(0).begin();
}

void DelayOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type act, ::mlir::Value dur, ::mlir::Value cha) {
  odsState.addOperands(dur);
  odsState.addOperands(cha);
  odsState.addTypes(act);
}

void DelayOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value dur, ::mlir::Value cha) {
  odsState.addOperands(dur);
  odsState.addOperands(cha);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void DelayOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 2u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult DelayOp::verify() {
  if (failed(DelayOpAdaptor(*this).verify((*this)->getLoc()))) return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps0(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
    auto valueGroup1 = getODSOperands(1);
    for (::mlir::Value v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps1(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps3(getOperation(), v.getType(), "result", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  return ::mlir::success();
}

::mlir::ParseResult DelayOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::OperandType durRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::OperandType> durOperands(durRawOperands);  ::llvm::SMLoc durOperandsLoc;
  (void)durOperandsLoc;
  ::mlir::OpAsmParser::OperandType chaRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::OperandType> chaOperands(chaRawOperands);  ::llvm::SMLoc chaOperandsLoc;
  (void)chaOperandsLoc;
  ::mlir::Type durRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> durTypes(durRawTypes);
  ::mlir::Type chaRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> chaTypes(chaRawTypes);
  ::mlir::Type actRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> actTypes(actRawTypes);
  if (parser.parseOptionalAttrDict(result.attributes))
    return ::mlir::failure();
  if (parser.parseLParen())
    return ::mlir::failure();

  durOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(durRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  chaOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(chaRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  if (parser.parseColon())
    return ::mlir::failure();
  if (parser.parseLParen())
    return ::mlir::failure();

  if (parser.parseType(durRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  if (parser.parseType(chaRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  if (parser.parseArrow())
    return ::mlir::failure();

  if (parser.parseType(actRawTypes[0]))
    return ::mlir::failure();
  result.addTypes(actTypes);
  if (parser.resolveOperands(durOperands, durTypes, durOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(chaOperands, chaTypes, chaOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void DelayOp::print(::mlir::OpAsmPrinter &p) {
  p << "pulse.delay";
  p.printOptionalAttrDict((*this)->getAttrs(), /*elidedAttrs=*/{});
  p << "(";
  p << dur();
  p << ",";
  p << ' ';
  p << cha();
  p << ")";
  p << ' ' << ":";
  p << ' ' << "(";
  p << ::llvm::ArrayRef<::mlir::Type>(dur().getType());
  p << ",";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(cha().getType());
  p << ")";
  p << ' ' << "->";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(act().getType());
}

} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {

//===----------------------------------------------------------------------===//
// ::mlir::pulse::DragOp definitions
//===----------------------------------------------------------------------===//

DragOpAdaptor::DragOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs, ::mlir::RegionRange regions)  : odsOperands(values), odsAttrs(attrs), odsRegions(regions) {

}

DragOpAdaptor::DragOpAdaptor(DragOp&op)  : odsOperands(op->getOperands()), odsAttrs(op->getAttrDictionary()), odsRegions(op->getRegions()) {

}

::mlir::ValueRange DragOpAdaptor::getOperands() {
  return odsOperands;
}

std::pair<unsigned, unsigned> DragOpAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::ValueRange DragOpAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

::mlir::Value DragOpAdaptor::dur() {
  return *getODSOperands(0).begin();
}

::mlir::Value DragOpAdaptor::sig() {
  return *getODSOperands(1).begin();
}

::mlir::Value DragOpAdaptor::beta() {
  return *getODSOperands(2).begin();
}

::mlir::Value DragOpAdaptor::amp() {
  return *getODSOperands(3).begin();
}

::mlir::Value DragOpAdaptor::angle() {
  return *getODSOperands(4).begin();
}

::mlir::DictionaryAttr DragOpAdaptor::getAttributes() {
  return odsAttrs;
}

::mlir::LogicalResult DragOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}



std::pair<unsigned, unsigned> DragOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range DragOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value DragOp::dur() {
  return *getODSOperands(0).begin();
}

::mlir::Value DragOp::sig() {
  return *getODSOperands(1).begin();
}

::mlir::Value DragOp::beta() {
  return *getODSOperands(2).begin();
}

::mlir::Value DragOp::amp() {
  return *getODSOperands(3).begin();
}

::mlir::Value DragOp::angle() {
  return *getODSOperands(4).begin();
}

::mlir::MutableOperandRange DragOp::durMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

::mlir::MutableOperandRange DragOp::sigMutable() {
  auto range = getODSOperandIndexAndLength(1);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

::mlir::MutableOperandRange DragOp::betaMutable() {
  auto range = getODSOperandIndexAndLength(2);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

::mlir::MutableOperandRange DragOp::ampMutable() {
  auto range = getODSOperandIndexAndLength(3);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

::mlir::MutableOperandRange DragOp::angleMutable() {
  auto range = getODSOperandIndexAndLength(4);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> DragOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range DragOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value DragOp::wav() {
  return *getODSResults(0).begin();
}

void DragOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type wav, ::mlir::Value dur, ::mlir::Value sig, ::mlir::Value beta, ::mlir::Value amp, ::mlir::Value angle) {
  odsState.addOperands(dur);
  odsState.addOperands(sig);
  odsState.addOperands(beta);
  odsState.addOperands(amp);
  odsState.addOperands(angle);
  odsState.addTypes(wav);
}

void DragOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value dur, ::mlir::Value sig, ::mlir::Value beta, ::mlir::Value amp, ::mlir::Value angle) {
  odsState.addOperands(dur);
  odsState.addOperands(sig);
  odsState.addOperands(beta);
  odsState.addOperands(amp);
  odsState.addOperands(angle);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void DragOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 5u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult DragOp::verify() {
  if (failed(DragOpAdaptor(*this).verify((*this)->getLoc()))) return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps0(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
    auto valueGroup1 = getODSOperands(1);
    for (::mlir::Value v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps0(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
    auto valueGroup2 = getODSOperands(2);
    for (::mlir::Value v : valueGroup2) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps4(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
    auto valueGroup3 = getODSOperands(3);
    for (::mlir::Value v : valueGroup3) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps5(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
    auto valueGroup4 = getODSOperands(4);
    for (::mlir::Value v : valueGroup4) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps4(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps6(getOperation(), v.getType(), "result", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  return ::mlir::success();
}

::mlir::ParseResult DragOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::OperandType durRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::OperandType> durOperands(durRawOperands);  ::llvm::SMLoc durOperandsLoc;
  (void)durOperandsLoc;
  ::mlir::OpAsmParser::OperandType sigRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::OperandType> sigOperands(sigRawOperands);  ::llvm::SMLoc sigOperandsLoc;
  (void)sigOperandsLoc;
  ::mlir::OpAsmParser::OperandType betaRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::OperandType> betaOperands(betaRawOperands);  ::llvm::SMLoc betaOperandsLoc;
  (void)betaOperandsLoc;
  ::mlir::OpAsmParser::OperandType ampRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::OperandType> ampOperands(ampRawOperands);  ::llvm::SMLoc ampOperandsLoc;
  (void)ampOperandsLoc;
  ::mlir::OpAsmParser::OperandType angleRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::OperandType> angleOperands(angleRawOperands);  ::llvm::SMLoc angleOperandsLoc;
  (void)angleOperandsLoc;
  ::mlir::Type durRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> durTypes(durRawTypes);
  ::mlir::Type sigRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> sigTypes(sigRawTypes);
  ::mlir::Type betaRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> betaTypes(betaRawTypes);
  ::mlir::Type ampRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> ampTypes(ampRawTypes);
  ::mlir::Type angleRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> angleTypes(angleRawTypes);
  ::mlir::Type wavRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> wavTypes(wavRawTypes);
  if (parser.parseOptionalAttrDict(result.attributes))
    return ::mlir::failure();
  if (parser.parseLParen())
    return ::mlir::failure();

  durOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(durRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  sigOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(sigRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  betaOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(betaRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  ampOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(ampRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  angleOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(angleRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  if (parser.parseColon())
    return ::mlir::failure();
  if (parser.parseLParen())
    return ::mlir::failure();

  if (parser.parseType(durRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  if (parser.parseType(sigRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  if (parser.parseType(betaRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  if (parser.parseType(ampRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  if (parser.parseType(angleRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  if (parser.parseArrow())
    return ::mlir::failure();

  if (parser.parseType(wavRawTypes[0]))
    return ::mlir::failure();
  result.addTypes(wavTypes);
  if (parser.resolveOperands(durOperands, durTypes, durOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(sigOperands, sigTypes, sigOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(betaOperands, betaTypes, betaOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(ampOperands, ampTypes, ampOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(angleOperands, angleTypes, angleOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void DragOp::print(::mlir::OpAsmPrinter &p) {
  p << "pulse.drag";
  p.printOptionalAttrDict((*this)->getAttrs(), /*elidedAttrs=*/{});
  p << "(";
  p << dur();
  p << ",";
  p << ' ';
  p << sig();
  p << ",";
  p << ' ';
  p << beta();
  p << ",";
  p << ' ';
  p << amp();
  p << ",";
  p << ' ';
  p << angle();
  p << ")";
  p << ' ' << ":";
  p << ' ' << "(";
  p << ::llvm::ArrayRef<::mlir::Type>(dur().getType());
  p << ",";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(sig().getType());
  p << ",";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(beta().getType());
  p << ",";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(amp().getType());
  p << ",";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(angle().getType());
  p << ")";
  p << ' ' << "->";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(wav().getType());
}

} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {

//===----------------------------------------------------------------------===//
// ::mlir::pulse::GaussianSquareOp definitions
//===----------------------------------------------------------------------===//

GaussianSquareOpAdaptor::GaussianSquareOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs, ::mlir::RegionRange regions)  : odsOperands(values), odsAttrs(attrs), odsRegions(regions) {

}

GaussianSquareOpAdaptor::GaussianSquareOpAdaptor(GaussianSquareOp&op)  : odsOperands(op->getOperands()), odsAttrs(op->getAttrDictionary()), odsRegions(op->getRegions()) {

}

::mlir::ValueRange GaussianSquareOpAdaptor::getOperands() {
  return odsOperands;
}

std::pair<unsigned, unsigned> GaussianSquareOpAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::ValueRange GaussianSquareOpAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

::mlir::Value GaussianSquareOpAdaptor::dur() {
  return *getODSOperands(0).begin();
}

::mlir::Value GaussianSquareOpAdaptor::sig() {
  return *getODSOperands(1).begin();
}

::mlir::Value GaussianSquareOpAdaptor::width() {
  return *getODSOperands(2).begin();
}

::mlir::Value GaussianSquareOpAdaptor::amp() {
  return *getODSOperands(3).begin();
}

::mlir::Value GaussianSquareOpAdaptor::angle() {
  return *getODSOperands(4).begin();
}

::mlir::DictionaryAttr GaussianSquareOpAdaptor::getAttributes() {
  return odsAttrs;
}

::mlir::LogicalResult GaussianSquareOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}



std::pair<unsigned, unsigned> GaussianSquareOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range GaussianSquareOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value GaussianSquareOp::dur() {
  return *getODSOperands(0).begin();
}

::mlir::Value GaussianSquareOp::sig() {
  return *getODSOperands(1).begin();
}

::mlir::Value GaussianSquareOp::width() {
  return *getODSOperands(2).begin();
}

::mlir::Value GaussianSquareOp::amp() {
  return *getODSOperands(3).begin();
}

::mlir::Value GaussianSquareOp::angle() {
  return *getODSOperands(4).begin();
}

::mlir::MutableOperandRange GaussianSquareOp::durMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

::mlir::MutableOperandRange GaussianSquareOp::sigMutable() {
  auto range = getODSOperandIndexAndLength(1);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

::mlir::MutableOperandRange GaussianSquareOp::widthMutable() {
  auto range = getODSOperandIndexAndLength(2);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

::mlir::MutableOperandRange GaussianSquareOp::ampMutable() {
  auto range = getODSOperandIndexAndLength(3);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

::mlir::MutableOperandRange GaussianSquareOp::angleMutable() {
  auto range = getODSOperandIndexAndLength(4);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> GaussianSquareOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range GaussianSquareOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value GaussianSquareOp::wav() {
  return *getODSResults(0).begin();
}

void GaussianSquareOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type wav, ::mlir::Value dur, ::mlir::Value sig, ::mlir::Value width, ::mlir::Value amp, ::mlir::Value angle) {
  odsState.addOperands(dur);
  odsState.addOperands(sig);
  odsState.addOperands(width);
  odsState.addOperands(amp);
  odsState.addOperands(angle);
  odsState.addTypes(wav);
}

void GaussianSquareOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value dur, ::mlir::Value sig, ::mlir::Value width, ::mlir::Value amp, ::mlir::Value angle) {
  odsState.addOperands(dur);
  odsState.addOperands(sig);
  odsState.addOperands(width);
  odsState.addOperands(amp);
  odsState.addOperands(angle);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void GaussianSquareOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 5u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult GaussianSquareOp::verify() {
  if (failed(GaussianSquareOpAdaptor(*this).verify((*this)->getLoc()))) return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps0(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
    auto valueGroup1 = getODSOperands(1);
    for (::mlir::Value v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps0(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
    auto valueGroup2 = getODSOperands(2);
    for (::mlir::Value v : valueGroup2) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps0(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
    auto valueGroup3 = getODSOperands(3);
    for (::mlir::Value v : valueGroup3) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps5(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
    auto valueGroup4 = getODSOperands(4);
    for (::mlir::Value v : valueGroup4) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps4(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps6(getOperation(), v.getType(), "result", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  return ::mlir::success();
}

::mlir::ParseResult GaussianSquareOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::OperandType durRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::OperandType> durOperands(durRawOperands);  ::llvm::SMLoc durOperandsLoc;
  (void)durOperandsLoc;
  ::mlir::OpAsmParser::OperandType sigRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::OperandType> sigOperands(sigRawOperands);  ::llvm::SMLoc sigOperandsLoc;
  (void)sigOperandsLoc;
  ::mlir::OpAsmParser::OperandType widthRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::OperandType> widthOperands(widthRawOperands);  ::llvm::SMLoc widthOperandsLoc;
  (void)widthOperandsLoc;
  ::mlir::OpAsmParser::OperandType ampRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::OperandType> ampOperands(ampRawOperands);  ::llvm::SMLoc ampOperandsLoc;
  (void)ampOperandsLoc;
  ::mlir::OpAsmParser::OperandType angleRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::OperandType> angleOperands(angleRawOperands);  ::llvm::SMLoc angleOperandsLoc;
  (void)angleOperandsLoc;
  ::mlir::Type durRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> durTypes(durRawTypes);
  ::mlir::Type sigRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> sigTypes(sigRawTypes);
  ::mlir::Type widthRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> widthTypes(widthRawTypes);
  ::mlir::Type ampRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> ampTypes(ampRawTypes);
  ::mlir::Type angleRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> angleTypes(angleRawTypes);
  ::mlir::Type wavRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> wavTypes(wavRawTypes);
  if (parser.parseOptionalAttrDict(result.attributes))
    return ::mlir::failure();
  if (parser.parseLParen())
    return ::mlir::failure();

  durOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(durRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  sigOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(sigRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  widthOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(widthRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  ampOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(ampRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  angleOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(angleRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  if (parser.parseColon())
    return ::mlir::failure();
  if (parser.parseLParen())
    return ::mlir::failure();

  if (parser.parseType(durRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  if (parser.parseType(sigRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  if (parser.parseType(widthRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  if (parser.parseType(ampRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  if (parser.parseType(angleRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  if (parser.parseArrow())
    return ::mlir::failure();

  if (parser.parseType(wavRawTypes[0]))
    return ::mlir::failure();
  result.addTypes(wavTypes);
  if (parser.resolveOperands(durOperands, durTypes, durOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(sigOperands, sigTypes, sigOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(widthOperands, widthTypes, widthOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(ampOperands, ampTypes, ampOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(angleOperands, angleTypes, angleOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void GaussianSquareOp::print(::mlir::OpAsmPrinter &p) {
  p << "pulse.gaussian_square";
  p.printOptionalAttrDict((*this)->getAttrs(), /*elidedAttrs=*/{});
  p << "(";
  p << dur();
  p << ",";
  p << ' ';
  p << sig();
  p << ",";
  p << ' ';
  p << width();
  p << ",";
  p << ' ';
  p << amp();
  p << ",";
  p << ' ';
  p << angle();
  p << ")";
  p << ' ' << ":";
  p << ' ' << "(";
  p << ::llvm::ArrayRef<::mlir::Type>(dur().getType());
  p << ",";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(sig().getType());
  p << ",";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(width().getType());
  p << ",";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(amp().getType());
  p << ",";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(angle().getType());
  p << ")";
  p << ' ' << "->";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(wav().getType());
}

} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {

//===----------------------------------------------------------------------===//
// ::mlir::pulse::InitializeChannelsOp definitions
//===----------------------------------------------------------------------===//

InitializeChannelsOpAdaptor::InitializeChannelsOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs, ::mlir::RegionRange regions)  : odsOperands(values), odsAttrs(attrs), odsRegions(regions) {

}

InitializeChannelsOpAdaptor::InitializeChannelsOpAdaptor(InitializeChannelsOp&op)  : odsOperands(op->getOperands()), odsAttrs(op->getAttrDictionary()), odsRegions(op->getRegions()) {

}

::mlir::ValueRange InitializeChannelsOpAdaptor::getOperands() {
  return odsOperands;
}

std::pair<unsigned, unsigned> InitializeChannelsOpAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::ValueRange InitializeChannelsOpAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

::mlir::DictionaryAttr InitializeChannelsOpAdaptor::getAttributes() {
  return odsAttrs;
}

::mlir::LogicalResult InitializeChannelsOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

void InitializeChannelsOp::getAsmResultNames(::mlir::OpAsmSetValueNameFn setNameFn) {
  auto resultGroup0 = getODSResults(0);
  if (!llvm::empty(resultGroup0))
    setNameFn(*resultGroup0.begin(), "dc");
  auto resultGroup1 = getODSResults(1);
  if (!llvm::empty(resultGroup1))
    setNameFn(*resultGroup1.begin(), "cc");
  auto resultGroup2 = getODSResults(2);
  if (!llvm::empty(resultGroup2))
    setNameFn(*resultGroup2.begin(), "mc");
  auto resultGroup3 = getODSResults(3);
  if (!llvm::empty(resultGroup3))
    setNameFn(*resultGroup3.begin(), "ac");
}



std::pair<unsigned, unsigned> InitializeChannelsOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range InitializeChannelsOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

std::pair<unsigned, unsigned> InitializeChannelsOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range InitializeChannelsOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value InitializeChannelsOp::dc() {
  return *getODSResults(0).begin();
}

::mlir::Value InitializeChannelsOp::cc() {
  return *getODSResults(1).begin();
}

::mlir::Value InitializeChannelsOp::mc() {
  return *getODSResults(2).begin();
}

::mlir::Value InitializeChannelsOp::ac() {
  return *getODSResults(3).begin();
}

void InitializeChannelsOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type dc, ::mlir::Type cc, ::mlir::Type mc, ::mlir::Type ac) {
  odsState.addTypes(dc);
  odsState.addTypes(cc);
  odsState.addTypes(mc);
  odsState.addTypes(ac);
}

void InitializeChannelsOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes) {
  assert(resultTypes.size() == 4u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void InitializeChannelsOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 4u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult InitializeChannelsOp::verify() {
  if (failed(InitializeChannelsOpAdaptor(*this).verify((*this)->getLoc()))) return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps7(getOperation(), v.getType(), "result", index)))
        return ::mlir::failure();
      ++index;
    }
    auto valueGroup1 = getODSResults(1);
    for (::mlir::Value v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps8(getOperation(), v.getType(), "result", index)))
        return ::mlir::failure();
      ++index;
    }
    auto valueGroup2 = getODSResults(2);
    for (::mlir::Value v : valueGroup2) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps9(getOperation(), v.getType(), "result", index)))
        return ::mlir::failure();
      ++index;
    }
    auto valueGroup3 = getODSResults(3);
    for (::mlir::Value v : valueGroup3) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps10(getOperation(), v.getType(), "result", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  return ::mlir::success();
}

::mlir::ParseResult InitializeChannelsOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::Type dcRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> dcTypes(dcRawTypes);
  ::mlir::Type ccRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> ccTypes(ccRawTypes);
  ::mlir::Type mcRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> mcTypes(mcRawTypes);
  ::mlir::Type acRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> acTypes(acRawTypes);
  if (parser.parseOptionalAttrDict(result.attributes))
    return ::mlir::failure();
  if (parser.parseLParen())
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  if (parser.parseColon())
    return ::mlir::failure();
  if (parser.parseLParen())
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  if (parser.parseArrow())
    return ::mlir::failure();
  if (parser.parseLParen())
    return ::mlir::failure();

  if (parser.parseType(dcRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  if (parser.parseType(ccRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  if (parser.parseType(mcRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  if (parser.parseType(acRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  result.addTypes(dcTypes);
  result.addTypes(ccTypes);
  result.addTypes(mcTypes);
  result.addTypes(acTypes);
  return ::mlir::success();
}

void InitializeChannelsOp::print(::mlir::OpAsmPrinter &p) {
  p << "pulse.initialize_channels";
  p.printOptionalAttrDict((*this)->getAttrs(), /*elidedAttrs=*/{});
  p << "(";
  p << ")";
  p << ' ' << ":";
  p << ' ' << "(";
  p << ")";
  p << ' ' << "->";
  p << ' ' << "(";
  p << ::llvm::ArrayRef<::mlir::Type>(dc().getType());
  p << ",";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(cc().getType());
  p << ",";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(mc().getType());
  p << ",";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(ac().getType());
  p << ")";
}

} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {

//===----------------------------------------------------------------------===//
// ::mlir::pulse::InitializeMemorySlotOp definitions
//===----------------------------------------------------------------------===//

InitializeMemorySlotOpAdaptor::InitializeMemorySlotOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs, ::mlir::RegionRange regions)  : odsOperands(values), odsAttrs(attrs), odsRegions(regions) {

}

InitializeMemorySlotOpAdaptor::InitializeMemorySlotOpAdaptor(InitializeMemorySlotOp&op)  : odsOperands(op->getOperands()), odsAttrs(op->getAttrDictionary()), odsRegions(op->getRegions()) {

}

::mlir::ValueRange InitializeMemorySlotOpAdaptor::getOperands() {
  return odsOperands;
}

std::pair<unsigned, unsigned> InitializeMemorySlotOpAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::ValueRange InitializeMemorySlotOpAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

::mlir::DictionaryAttr InitializeMemorySlotOpAdaptor::getAttributes() {
  return odsAttrs;
}

::mlir::LogicalResult InitializeMemorySlotOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}



std::pair<unsigned, unsigned> InitializeMemorySlotOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range InitializeMemorySlotOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

std::pair<unsigned, unsigned> InitializeMemorySlotOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range InitializeMemorySlotOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value InitializeMemorySlotOp::ms() {
  return *getODSResults(0).begin();
}

void InitializeMemorySlotOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type ms) {
  odsState.addTypes(ms);
}

void InitializeMemorySlotOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes) {
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void InitializeMemorySlotOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult InitializeMemorySlotOp::verify() {
  if (failed(InitializeMemorySlotOpAdaptor(*this).verify((*this)->getLoc()))) return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps2(getOperation(), v.getType(), "result", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  return ::mlir::success();
}

::mlir::ParseResult InitializeMemorySlotOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::Type msRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> msTypes(msRawTypes);
  if (parser.parseOptionalAttrDict(result.attributes))
    return ::mlir::failure();
  if (parser.parseLParen())
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  if (parser.parseColon())
    return ::mlir::failure();
  if (parser.parseLParen())
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  if (parser.parseArrow())
    return ::mlir::failure();

  if (parser.parseType(msRawTypes[0]))
    return ::mlir::failure();
  result.addTypes(msTypes);
  return ::mlir::success();
}

void InitializeMemorySlotOp::print(::mlir::OpAsmPrinter &p) {
  p << "pulse.initialize_memory_slot";
  p.printOptionalAttrDict((*this)->getAttrs(), /*elidedAttrs=*/{});
  p << "(";
  p << ")";
  p << ' ' << ":";
  p << ' ' << "(";
  p << ")";
  p << ' ' << "->";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(ms().getType());
}

} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {

//===----------------------------------------------------------------------===//
// ::mlir::pulse::PlayOp definitions
//===----------------------------------------------------------------------===//

PlayOpAdaptor::PlayOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs, ::mlir::RegionRange regions)  : odsOperands(values), odsAttrs(attrs), odsRegions(regions) {

}

PlayOpAdaptor::PlayOpAdaptor(PlayOp&op)  : odsOperands(op->getOperands()), odsAttrs(op->getAttrDictionary()), odsRegions(op->getRegions()) {

}

::mlir::ValueRange PlayOpAdaptor::getOperands() {
  return odsOperands;
}

std::pair<unsigned, unsigned> PlayOpAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::ValueRange PlayOpAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

::mlir::Value PlayOpAdaptor::wav() {
  return *getODSOperands(0).begin();
}

::mlir::Value PlayOpAdaptor::cha() {
  return *getODSOperands(1).begin();
}

::mlir::DictionaryAttr PlayOpAdaptor::getAttributes() {
  return odsAttrs;
}

::mlir::LogicalResult PlayOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}



std::pair<unsigned, unsigned> PlayOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range PlayOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value PlayOp::wav() {
  return *getODSOperands(0).begin();
}

::mlir::Value PlayOp::cha() {
  return *getODSOperands(1).begin();
}

::mlir::MutableOperandRange PlayOp::wavMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

::mlir::MutableOperandRange PlayOp::chaMutable() {
  auto range = getODSOperandIndexAndLength(1);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> PlayOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range PlayOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value PlayOp::act() {
  return *getODSResults(0).begin();
}

void PlayOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type act, ::mlir::Value wav, ::mlir::Value cha) {
  odsState.addOperands(wav);
  odsState.addOperands(cha);
  odsState.addTypes(act);
}

void PlayOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value wav, ::mlir::Value cha) {
  odsState.addOperands(wav);
  odsState.addOperands(cha);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void PlayOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 2u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult PlayOp::verify() {
  if (failed(PlayOpAdaptor(*this).verify((*this)->getLoc()))) return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps6(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
    auto valueGroup1 = getODSOperands(1);
    for (::mlir::Value v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps1(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps3(getOperation(), v.getType(), "result", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  return ::mlir::success();
}

::mlir::ParseResult PlayOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::OperandType wavRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::OperandType> wavOperands(wavRawOperands);  ::llvm::SMLoc wavOperandsLoc;
  (void)wavOperandsLoc;
  ::mlir::OpAsmParser::OperandType chaRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::OperandType> chaOperands(chaRawOperands);  ::llvm::SMLoc chaOperandsLoc;
  (void)chaOperandsLoc;
  ::mlir::Type wavRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> wavTypes(wavRawTypes);
  ::mlir::Type chaRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> chaTypes(chaRawTypes);
  ::mlir::Type actRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> actTypes(actRawTypes);
  if (parser.parseOptionalAttrDict(result.attributes))
    return ::mlir::failure();
  if (parser.parseLParen())
    return ::mlir::failure();

  wavOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(wavRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  chaOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(chaRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  if (parser.parseColon())
    return ::mlir::failure();
  if (parser.parseLParen())
    return ::mlir::failure();

  if (parser.parseType(wavRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  if (parser.parseType(chaRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  if (parser.parseArrow())
    return ::mlir::failure();

  if (parser.parseType(actRawTypes[0]))
    return ::mlir::failure();
  result.addTypes(actTypes);
  if (parser.resolveOperands(wavOperands, wavTypes, wavOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(chaOperands, chaTypes, chaOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void PlayOp::print(::mlir::OpAsmPrinter &p) {
  p << "pulse.play";
  p.printOptionalAttrDict((*this)->getAttrs(), /*elidedAttrs=*/{});
  p << "(";
  p << wav();
  p << ",";
  p << ' ';
  p << cha();
  p << ")";
  p << ' ' << ":";
  p << ' ' << "(";
  p << ::llvm::ArrayRef<::mlir::Type>(wav().getType());
  p << ",";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(cha().getType());
  p << ")";
  p << ' ' << "->";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(act().getType());
}

} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {

//===----------------------------------------------------------------------===//
// ::mlir::pulse::ScheduleOp definitions
//===----------------------------------------------------------------------===//

ScheduleOpAdaptor::ScheduleOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs, ::mlir::RegionRange regions)  : odsOperands(values), odsAttrs(attrs), odsRegions(regions) {

}

ScheduleOpAdaptor::ScheduleOpAdaptor(ScheduleOp&op)  : odsOperands(op->getOperands()), odsAttrs(op->getAttrDictionary()), odsRegions(op->getRegions()) {

}

::mlir::ValueRange ScheduleOpAdaptor::getOperands() {
  return odsOperands;
}

std::pair<unsigned, unsigned> ScheduleOpAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::ValueRange ScheduleOpAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

::mlir::Value ScheduleOpAdaptor::time() {
  return *getODSOperands(0).begin();
}

::mlir::Value ScheduleOpAdaptor::act() {
  return *getODSOperands(1).begin();
}

::mlir::DictionaryAttr ScheduleOpAdaptor::getAttributes() {
  return odsAttrs;
}

::mlir::LogicalResult ScheduleOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}



std::pair<unsigned, unsigned> ScheduleOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range ScheduleOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value ScheduleOp::time() {
  return *getODSOperands(0).begin();
}

::mlir::Value ScheduleOp::act() {
  return *getODSOperands(1).begin();
}

::mlir::MutableOperandRange ScheduleOp::timeMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

::mlir::MutableOperandRange ScheduleOp::actMutable() {
  auto range = getODSOperandIndexAndLength(1);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> ScheduleOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range ScheduleOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

void ScheduleOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value time, ::mlir::Value act) {
  odsState.addOperands(time);
  odsState.addOperands(act);
}

void ScheduleOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value time, ::mlir::Value act) {
  odsState.addOperands(time);
  odsState.addOperands(act);
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ScheduleOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 2u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult ScheduleOp::verify() {
  if (failed(ScheduleOpAdaptor(*this).verify((*this)->getLoc()))) return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps0(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
    auto valueGroup1 = getODSOperands(1);
    for (::mlir::Value v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps3(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
  }
  return ::mlir::success();
}

::mlir::ParseResult ScheduleOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::OperandType timeRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::OperandType> timeOperands(timeRawOperands);  ::llvm::SMLoc timeOperandsLoc;
  (void)timeOperandsLoc;
  ::mlir::OpAsmParser::OperandType actRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::OperandType> actOperands(actRawOperands);  ::llvm::SMLoc actOperandsLoc;
  (void)actOperandsLoc;
  ::mlir::Type timeRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> timeTypes(timeRawTypes);
  ::mlir::Type actRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> actTypes(actRawTypes);
  if (parser.parseOptionalAttrDict(result.attributes))
    return ::mlir::failure();
  if (parser.parseLParen())
    return ::mlir::failure();

  timeOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(timeRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  actOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(actRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  if (parser.parseColon())
    return ::mlir::failure();
  if (parser.parseLParen())
    return ::mlir::failure();

  if (parser.parseType(timeRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  if (parser.parseType(actRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  if (parser.resolveOperands(timeOperands, timeTypes, timeOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(actOperands, actTypes, actOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void ScheduleOp::print(::mlir::OpAsmPrinter &p) {
  p << "pulse.schedule";
  p.printOptionalAttrDict((*this)->getAttrs(), /*elidedAttrs=*/{});
  p << "(";
  p << time();
  p << ",";
  p << ' ';
  p << act();
  p << ")";
  p << ' ' << ":";
  p << ' ' << "(";
  p << ::llvm::ArrayRef<::mlir::Type>(time().getType());
  p << ",";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(act().getType());
  p << ")";
}

} // namespace pulse
} // namespace mlir
namespace mlir {
namespace pulse {

//===----------------------------------------------------------------------===//
// ::mlir::pulse::ShiftPhaseOp definitions
//===----------------------------------------------------------------------===//

ShiftPhaseOpAdaptor::ShiftPhaseOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs, ::mlir::RegionRange regions)  : odsOperands(values), odsAttrs(attrs), odsRegions(regions) {

}

ShiftPhaseOpAdaptor::ShiftPhaseOpAdaptor(ShiftPhaseOp&op)  : odsOperands(op->getOperands()), odsAttrs(op->getAttrDictionary()), odsRegions(op->getRegions()) {

}

::mlir::ValueRange ShiftPhaseOpAdaptor::getOperands() {
  return odsOperands;
}

std::pair<unsigned, unsigned> ShiftPhaseOpAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::ValueRange ShiftPhaseOpAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

::mlir::Value ShiftPhaseOpAdaptor::phase() {
  return *getODSOperands(0).begin();
}

::mlir::Value ShiftPhaseOpAdaptor::cha() {
  return *getODSOperands(1).begin();
}

::mlir::DictionaryAttr ShiftPhaseOpAdaptor::getAttributes() {
  return odsAttrs;
}

::mlir::LogicalResult ShiftPhaseOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}



std::pair<unsigned, unsigned> ShiftPhaseOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range ShiftPhaseOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value ShiftPhaseOp::phase() {
  return *getODSOperands(0).begin();
}

::mlir::Value ShiftPhaseOp::cha() {
  return *getODSOperands(1).begin();
}

::mlir::MutableOperandRange ShiftPhaseOp::phaseMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

::mlir::MutableOperandRange ShiftPhaseOp::chaMutable() {
  auto range = getODSOperandIndexAndLength(1);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> ShiftPhaseOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range ShiftPhaseOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

void ShiftPhaseOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value phase, ::mlir::Value cha) {
  odsState.addOperands(phase);
  odsState.addOperands(cha);
}

void ShiftPhaseOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value phase, ::mlir::Value cha) {
  odsState.addOperands(phase);
  odsState.addOperands(cha);
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ShiftPhaseOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 2u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

::mlir::LogicalResult ShiftPhaseOp::verify() {
  if (failed(ShiftPhaseOpAdaptor(*this).verify((*this)->getLoc()))) return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps4(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
    auto valueGroup1 = getODSOperands(1);
    for (::mlir::Value v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_PulseOps1(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
  }
  return ::mlir::success();
}

::mlir::ParseResult ShiftPhaseOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::OperandType phaseRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::OperandType> phaseOperands(phaseRawOperands);  ::llvm::SMLoc phaseOperandsLoc;
  (void)phaseOperandsLoc;
  ::mlir::OpAsmParser::OperandType chaRawOperands[1];
  ::llvm::ArrayRef<::mlir::OpAsmParser::OperandType> chaOperands(chaRawOperands);  ::llvm::SMLoc chaOperandsLoc;
  (void)chaOperandsLoc;
  ::mlir::Type phaseRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> phaseTypes(phaseRawTypes);
  ::mlir::Type chaRawTypes[1];
  ::llvm::ArrayRef<::mlir::Type> chaTypes(chaRawTypes);
  if (parser.parseOptionalAttrDict(result.attributes))
    return ::mlir::failure();
  if (parser.parseLParen())
    return ::mlir::failure();

  phaseOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(phaseRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  chaOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(chaRawOperands[0]))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  if (parser.parseColon())
    return ::mlir::failure();
  if (parser.parseLParen())
    return ::mlir::failure();

  if (parser.parseType(phaseRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseComma())
    return ::mlir::failure();

  if (parser.parseType(chaRawTypes[0]))
    return ::mlir::failure();
  if (parser.parseRParen())
    return ::mlir::failure();
  if (parser.resolveOperands(phaseOperands, phaseTypes, phaseOperandsLoc, result.operands))
    return ::mlir::failure();
  if (parser.resolveOperands(chaOperands, chaTypes, chaOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void ShiftPhaseOp::print(::mlir::OpAsmPrinter &p) {
  p << "pulse.shift_phase";
  p.printOptionalAttrDict((*this)->getAttrs(), /*elidedAttrs=*/{});
  p << "(";
  p << phase();
  p << ",";
  p << ' ';
  p << cha();
  p << ")";
  p << ' ' << ":";
  p << ' ' << "(";
  p << ::llvm::ArrayRef<::mlir::Type>(phase().getType());
  p << ",";
  p << ' ';
  p << ::llvm::ArrayRef<::mlir::Type>(cha().getType());
  p << ")";
}

} // namespace pulse
} // namespace mlir

#endif  // GET_OP_CLASSES

