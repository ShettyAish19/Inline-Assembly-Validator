# Implementation Details

The validator is implemented in clean, modern C++ using standard libraries to ensure high performance and minimal external dependencies.

## Key Components

1. **The Rule Database (`std::map`):**
   We map target x86-64 instruction mnemonics (`movl`, `addl`, etc.) to their strictly defined operand requirements.
   
2. **The Register Verification Set (`std::set`):**
   Contains a lookup table of standard x86-64 physical registers (32-bit and 64-bit bounds).

3. **String Parsing Logic:**
   Leverages standard library stream delimiters to sanitize input strings, strip formatting decorators, and extract tokenized arguments.

4. **Integration with LLVM IR:**
   The validator reads `.ll` files dynamically, locating the `asm` tag to isolate inline instruction streams.