//===- PulseOps.td - Pulse dialect ops -----------------*- tablegen -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef PULSE_OPS
#define PULSE_OPS

include "mlir/IR/OpBase.td"
include "mlir/Interfaces/SideEffectInterfaces.td"
include "mlir/Interfaces/ControlFlowInterfaces.td"

include "Dialect/Pulse/PulseDialect.td"
include "Dialect/Pulse/PulseTypes.td"

def Pulse_InitializeChannelsOp : Pulse_Op<"initialize_channels", []> {
  let summary = "Initialize channels for a single qubit";
  let description = [{
    %dc0, %cc0, %mc0, %ac0 = pulse.initialize_channels() : (!pulse.drive_channel, !pulse.control_channel, !pulse.measure_channel, !pulse.acquire_channel)
  }];
  let results = (outs
    Pulse_DriveChannelType:$dc,
    Pulse_ControlChannelType:$cc,
    Pulse_MeasureChannelType:$mc,
    Pulse_AcquireChannelType:$ac
  );
  let assemblyFormat = [{ attr-dict `(` type($dc) `,` type($cc) `,` type($mc) `,` type($ac) `)` }];
}

def Pulse_DragOp : Pulse_Op<"drag", []> {
  let summary = "Create drag waveform";
  let description = [{
    %drag = pulse.drag(%dur, %sig, %beta, %amp, %angle) : (i32, i32, f64, f64, f64) -> !pulse.waveform
  }];
  let arguments = (ins
    AnyInteger:$dur,
    AnyInteger:$sig,
    AnyFloat:$beta,
    AnyFloat:$amp,
    AnyFloat:$angle
  );
  let results = (outs Pulse_WaveformType:$wav);
  let assemblyFormat = [{ attr-dict `(` $dur `,` $sig `,` $beta `,` $amp `,` $angle `)` `:` `(` type($dur) `,` type($sig) `,` type($beta) `,` type($amp) `,` type($angle) `)` `->` type($wav) }];
}

def Pulse_GaussianSquareOp : Pulse_Op<"gaussian_square", []> {
  let summary = "Create gaussian square waveform";
  let description = [{
    %gauss2 = pulse.gaussian_square(%dur, %sig, %width, %amp, %angle) : (i32, i32, i32, f64, f64) -> !pulse.waveform
  }];
  let arguments = (ins
    AnyInteger:$dur,
    AnyInteger:$sig,
    AnyInteger:$width,
    AnyFloat:$amp,
    AnyFloat:$angle
  );
  let results = (outs Pulse_WaveformType:$wav);
  let assemblyFormat = [{ attr-dict `(` $dur `,` $sig `,` $width `,` $amp `,` $angle `)` `:` `(` type($dur) `,` type($sig) `,` type($width) `,` type($amp) `,` type($angle) `)` `->` type($wav) }];
}

def Pulse_PlayOp : Pulse_Op<"play", []> {
  let summary = "Play a waveform on a channel";
  let description = [{
    pulse.play(%wav, %cha) : (!pulse.waveform, !pulse.drive_channel)
  }];
  let arguments = (ins
    Pulse_WaveformType:$wav,
    TransmitChannel:$cha
  );
  let assemblyFormat = [{ attr-dict `(` $wav `,` $cha `)` `:` `(` type($wav) `,` type($cha) `)` }];
}

def Pulse_DelayOp : Pulse_Op<"delay", []> {
  let summary = "Delay for a duration on a channel";
  let description = [{
    pulse.delay(%dur, %cha) : (i32, !pulse.drive_channel)
  }];
  let arguments = (ins
    AnyInteger:$dur,
    TransmitChannel:$cha
  );
  let assemblyFormat = [{ attr-dict `(` $dur `,` $cha `)` `:` `(` type($dur) `,` type($cha) `)` }];
}

def Pulse_AcquireOp : Pulse_Op<"acquire", []> {
  let summary = "Acquire value into a memory slot";
  let description = [{
    %res = pulse.acquire(%dur, %cha) : (i1, !pulse.drive_channel)
  }];
  let arguments = (ins
    AnyInteger:$dur,
    TransmitChannel:$cha
  );
  let results = (outs I1:$res);
  let assemblyFormat = [{ attr-dict `(` $dur `,` $cha `)` `:` `(` type($dur) `,` type($cha) `)` }];
}

def Pulse_ShiftPhaseOp : Pulse_Op<"shift_phase", []> {
  let summary = "Shift phase of a channel";
  let description = [{
    pulse.shift_phase(%phase, %cha) : (f64, !pulse.drive_channel)
  }];
  let arguments = (ins
    AnyFloat:$phase,
    TransmitChannel:$cha
  );
  let assemblyFormat = [{ attr-dict `(` $phase `,` $cha `)` `:` `(` type($phase) `,` type($cha) `)` }];
}

def Pulse_BarrierOp : Pulse_Op<"barrier", []> {
  let summary = "Synchronize channels with delays";
  let description = [{
    pulse.barrier(%dc0, %cc0, %mc0, %ac0) : (!pulse.drive_channel, !pulse.control_channel, !pulse.measure_channel, !pulse.acquire_channel)
  }];
  let arguments = (ins
    Pulse_DriveChannelType:$dc,
    Pulse_ControlChannelType:$cc,
    Pulse_MeasureChannelType:$mc,
    Pulse_AcquireChannelType:$ac
  );
  let assemblyFormat = [{ attr-dict `(` $dc `,` $cc `,` $mc `,` $ac `)` }];
}

#endif // PULSE_OPS
