//===- PulseDialect.td - Pulse dialect -----------*- tablegen -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef PULSE_DIALECT
#define PULSE_DIALECT

include "mlir/IR/OpBase.td"

//===----------------------------------------------------------------------===//
// Pulse dialect definition.
//===----------------------------------------------------------------------===//

def Pulse_Dialect : Dialect {
    let name = "pulse";
    let summary = "A pulse MLIR dialect.";
    let description = [{
        A WIP Pulse dialect for MLIR targeting superconducting quantum computers.
    }];
    let cppNamespace = "::mlir::pulse";
    let hasConstantMaterializer = 1;
}

//===----------------------------------------------------------------------===//
// Base pulse operation definition.
//===----------------------------------------------------------------------===//

class Pulse_Op<string mnemonic, list<OpTrait> traits = []> :
        Op<Pulse_Dialect, mnemonic, traits> {
    
    // For each op, the following static functions need to be defined
    //
    // * static ParseResult parse<op-c++-class-name>(OpAsmParser &parser,
    //                                               OperationState &state);
    // * static void print(OpAsmPrinter &p, <op-c++-class-name> op)
    // * static LogicalResult verify(<op-c++-class-name> op)
    let parser = [{ return ::parse$cppClass(parser, result); }];
    let printer = [{ ::print(*this, p); }];
    let verifier = [{ return ::verify(*this); }];
}

class Pulse_Type<string name> : TypeDef<Pulse_Dialect, name> {}

#endif // PULSE_DIALECT
