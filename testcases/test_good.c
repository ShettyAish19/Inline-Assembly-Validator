int main() {
    int a = 10, b = 20;

    // TC-01: Valid movl with register-to-register data movement
    asm("movl %%eax, %%ebx" : : );

    // TC-02: Valid addl operation (requires exactly 2 operands)
    asm("addl %%eax, %%ebx" : : );

    // TC-03: Valid subl operation with constant input
    asm("subl %0, %%eax" : : "r"(a));

    // TC-04: Valid push operation (requires exactly 1 operand)
    asm("push %%rax" : : );

    // TC-05: Valid pop operation (requires exactly 1 operand)
    asm("pop %%rbx" : : );

    // TC-06: Valid return instruction (requires 0 operands)
    asm("ret" : : );

    return 0;
}