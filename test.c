int main() {
int a = 10;
asm("movl $10, %eax");    // Should PASS
asm("addl %eax, %ebx");    // Should PASS
asm("addl %eax");          // Should ERROR (Missing operand)
asm("fakeinstr %eax");     // Should ERROR (Unknown)
asm("movl $1, %wrongreg"); // Should ERROR (Invalid register)
return 0;
}