func @qasm_main() {
    %a = qasm.allocate
    %b = qasm.allocate
    qasm.CX %a, %b
    %res = qasm.measure %a
    return
}
