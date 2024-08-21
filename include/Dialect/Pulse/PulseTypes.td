//===- PulseTypes.td - Pulse dialect Types -------------*- tablegen -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef PULSE_TYPES
#define PULSE_TYPES

include "mlir/IR/OpBase.td"
include "Dialect/Pulse/PulseDialect.td"

def Pulse_WaveformType : Pulse_Type<"Waveform"> {
  let mnemonic = "waveform";
}

def Pulse_DriveChannelType : Pulse_Type<"DriveChannel"> {
  let mnemonic = "drive_channel";
}

def Pulse_ControlChannelType : Pulse_Type<"ControlChannel"> {
  let mnemonic = "control_channel";
}

def Pulse_MeasureChannelType : Pulse_Type<"MeasureChannel"> {
  let mnemonic = "measure_channel";
}

def Pulse_AcquireChannelType : Pulse_Type<"AcquireChannel"> {
  let mnemonic = "acquire_channel";
}

def TransmitChannel : AnyTypeOf<[Pulse_DriveChannelType, Pulse_ControlChannelType, Pulse_MeasureChannelType]>;

#endif // PULSE_TYPES
