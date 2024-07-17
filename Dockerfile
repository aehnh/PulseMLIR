FROM ubuntu:22.04

LABEL maintainer="anders.choi@tum.de"

WORKDIR /
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    ninja-build \
    clang \
    git \
    python3 \
    python3-pip \
    zlib1g-dev \
    libtinfo5 \
    libedit-dev \
    libxml2-dev
RUN apt-get clean && rm -rf /var/lib/apt/lists/*
ENV DEBIAN_FRONTEND=noninteractive
RUN git clone https://github.com/llvm/llvm-project.git

WORKDIR /llvm-project
RUN git checkout 9816d43cff5ad7abb94eab94dcd205285675972a

# build and install LLVM with MLIR
RUN mkdir build
RUN cmake -S llvm -B build -G Ninja \
    -DLLVM_ENABLE_PROJECTS='mlir' \
    -DLLVM_INSTALL_UTILS=ON \
    -DCMAKE_INSTALL_PREFIX=install \
    -DCMAKE_BUILD_TYPE=Release
RUN ninja -C build install

WORKDIR /
RUN git clone https://github.com/aehnh/PulseMLIR.git

WORKDIR /PulseMLIR
RUN git submodule init
RUN git submodule update

# build and run tests for QSSA
RUN mkdir build
WORKDIR build
RUN cmake -G Ninja -S .. -B . \
    -DCMAKE_LINKER=lld \
    -DCMAKE_C_COMPILER=clang \
    -DCMAKE_CXX_COMPILER=clang++ \
    -DMLIR_DIR=/llvm-project/install/lib/cmake/mlir \
    -DLLVM_DIR=/llvm-project/install/lib/cmake/llvm \
    -DLLVM_EXTERNAL_LIT=/llvm-project/build/bin/llvm-lit \
    -DCMAKE_BUILD_TYPE=Release
RUN cmake --build . --target check-quantum-opt || true

# # convert example OpenQASM codes into QASM MLIR dialect
# WORKDIR /PulseMLIR
# RUN pip install qiskit==0.46.1
# RUN python3 tools/openqasm-to-mlir.py \
#     -i test/Translation/OpenQASM/from-paper/E2-teleportation.qasm \
#     -o test/Translation/OpenQASM/from-paper/E2-teleportation.mlir
# RUN python3 tools/openqasm-to-mlir.py \
#     -i test/Translation/OpenQASM/from-paper/E3-qft.qasm \
#     -o test/Translation/OpenQASM/from-paper/E3-qft.mlir
# RUN python3 tools/openqasm-to-mlir.py \
#     -i test/Translation/OpenQASM/from-paper/E4-inverse-qft-v1.qasm \
#     -o test/Translation/OpenQASM/from-paper/E4-inverse-qft-v1.mlir
# RUN python3 tools/openqasm-to-mlir.py \
#     -i test/Translation/OpenQASM/from-paper/E4-inverse-qft-v2.qasm \
#     -o test/Translation/OpenQASM/from-paper/E4-inverse-qft-v2.mlir
# RUN python3 tools/openqasm-to-mlir.py \
#     -i test/Translation/OpenQASM/from-paper/E5-ripple-carry-adder.qasm \
#     -o test/Translation/OpenQASM/from-paper/E5-ripple-carry-adder.mlir
# RUN python3 tools/openqasm-to-mlir.py \
#     -i test/Translation/OpenQASM/from-paper/E6-randomized-bench.qasm \
#     -o test/Translation/OpenQASM/from-paper/E6-randomized-bench.mlir
# RUN python3 tools/openqasm-to-mlir.py \
#     -i test/Translation/OpenQASM/from-paper/E7-quantum-process-tomography.qasm \
#     -o test/Translation/OpenQASM/from-paper/E7-quantum-process-tomography.mlir
# RUN python3 tools/openqasm-to-mlir.py \
#     -i test/Translation/OpenQASM/from-paper/E8-error-correction.qasm \
#     -o test/Translation/OpenQASM/from-paper/E8-error-correction.mlir

# # convert QASM MLIR dialect into Quantum (SSA) MLIR dialect
# # RUN build/bin/quantum-opt --convert-qasm-to-qssa \
# #     test/Translation/OpenQASM/from-paper/E2-teleportation.mlir \
# #     -o test/Translation/OpenQASM/from-paper/E2-teleportation-ssa.mlir
# RUN build/bin/quantum-opt --convert-qasm-to-qssa \
#     test/Translation/OpenQASM/from-paper/E3-qft.mlir \
#     -o test/Translation/OpenQASM/from-paper/E3-qft-ssa.mlir
# # RUN build/bin/quantum-opt --convert-qasm-to-qssa \
# #     test/Translation/OpenQASM/from-paper/E4-inverse-qft-v1.mlir \
# #     -o test/Translation/OpenQASM/from-paper/E4-inverse-qft-v1-ssa.mlir
# # RUN build/bin/quantum-opt --convert-qasm-to-qssa \
# #     test/Translation/OpenQASM/from-paper/E4-inverse-qft-v2.mlir \
# #     -o test/Translation/OpenQASM/from-paper/E4-inverse-qft-v2-ssa.mlir
# RUN build/bin/quantum-opt --convert-qasm-to-qssa \
#     test/Translation/OpenQASM/from-paper/E5-ripple-carry-adder.mlir \
#     -o test/Translation/OpenQASM/from-paper/E5-ripple-carry-adder-ssa.mlir
# RUN build/bin/quantum-opt --convert-qasm-to-qssa \
#     test/Translation/OpenQASM/from-paper/E6-randomized-bench.mlir \
#     -o test/Translation/OpenQASM/from-paper/E6-randomized-bench-ssa.mlir
# RUN build/bin/quantum-opt --convert-qasm-to-qssa \
#     test/Translation/OpenQASM/from-paper/E7-quantum-process-tomography.mlir \
#     -o test/Translation/OpenQASM/from-paper/E7-quantum-process-tomography-ssa.mlir
# # RUN build/bin/quantum-opt --convert-qasm-to-qssa \
# #     test/Translation/OpenQASM/from-paper/E8-error-correction.mlir \
# #     -o test/Translation/OpenQASM/from-paper/E8-error-correction-ssa.mlir
