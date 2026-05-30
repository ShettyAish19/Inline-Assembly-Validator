int main() {
    // TC-07: Invalid/Unknown assembly instruction (Mnemonic check)
    asm("fakeinstr %eax"); 

    // TC-08: Invalid register syntax / Unsupported register (Register check)
    asm("movl $1, %wrongreg"); 

    // TC-09: Operand mismatch for 2-operand instruction (addl with 1 operand)
    asm("addl %eax"); 

    // TC-10: Operand mismatch for 1-operand instruction (push with 2 operands)
    asm("push %eax, %ebx"); 

    // TC-11: Operand mismatch for 0-operand instruction (ret with an argument)
    asm("ret %eax"); 

    // TC-12: Empty or blank inline assembly statement
    asm(""); 

    return 0;
}