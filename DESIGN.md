#### 2. Create `DESIGN.md`
```markdown
# Design Document

## Architectural Approach
Our validator acts as a **static analysis pipeline** that intercepts the compiler workflow. 
Instead of operating purely on C source code (where inline assembly strings are difficult to safely extract due to macro expansions or preprocessor variables), we target **LLVM Intermediate Representation (IR)**. 

### Why LLVM IR?
1. **Normalization:** The Clang compiler frontend parses the C file and normalizes inline assembly blocks into a clean `call void asm` instruction.
2. **Robustness:** Parsing at the IR level bypasses lexical C preprocessor complexities.

### Workflow
1. **IR Emission:** The source C code is compiled down to an LLVM IR file (`.ll`).
2. **Extraction:** A stream-based reader scans the `.ll` file for `asm` nodes.
3. **Parsing:** The extracted assembly string is tokenized, removing syntactic metadata.
4. **Validation:** The tokens are run against a Rule Database containing constraints on instruction mnemonics, operand counts, and x86-64 physical register sets.

## Alternatives Considered
- **Direct AST Parsing (Clang Tooling):** We considered using `libclang` to parse the C AST directly. However, parsing the raw string literals inside the C AST is highly complex due to C string escapes and macros. Operating on LLVM IR was a much cleaner, lightweight, and robust approach.