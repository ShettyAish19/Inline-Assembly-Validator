# Static Inline Assembly Validator for x86-64

An educational **static analysis tool** designed to parse and validate **x86-64 inline assembly strings** extracted from **LLVM Intermediate Representation (IR)**.

Standard compilers often treat inline assembly blocks (`asm()`) as **unparsed literal strings**, passing them blindly to the assembler. When errors occur, they result in cryptic assembly-phase warnings. This project acts as an early **"Gatekeeper"**, intercepting the compilation pipeline at the **LLVM IR phase** to perform strict **syntactic and semantic validation** before execution.

---

## Features

* Parses **x86-64 inline assembly** extracted from LLVM IR
* Performs **syntactic validation** of assembly instructions
* Detects **semantic errors** such as:

  * Unknown instructions
  * Invalid registers
  * Incorrect operand counts
* Validates inline assembly **before assembler execution**
* Educational tool for understanding:

  * LLVM IR
  * Inline assembly
  * Compiler pipelines
  * Static program analysis

---

## Project Architecture

### Validation Pipeline

```text
C Source File
      ↓
Clang Compilation
      ↓
LLVM IR (.ll)
      ↓
Inline Assembly Extraction
      ↓
Static Validation Engine
      ↓
PASS / ERROR Report
```

The validator intercepts the LLVM compilation process after IR generation and performs validation on extracted inline assembly strings.

---

## Directory Structure

```text
inline-asm-validator/
├── src/
│   └── validator.cpp          # C++ Validator Engine (Parser + Semantics)
│
├── testcases/
│   ├── test_good.c            # 6 valid inline assembly examples
│   ├── test_bad.c             # 6 invalid inline assembly examples
│   └── test.ll                # Dynamically generated LLVM IR file
│
├── results/                   # Output screenshots and demo images
│
├── build.sh                   # Script to compile validator.cpp
├── run.sh                     # Script: C → LLVM IR → Validation
│
├── README.md                  # Project documentation
├── DESIGN.md                  # Architectural design details
├── IMPLEMENTATION.md          # Parsing logic and LLVM handling
└── EVALUATION.md              # Test matrix, limitations, failures
```

---

## Requirements & Prerequisites

Ensure the following dependencies are installed on your **Linux** or **Windows WSL** environment.

### Install Required Packages

```bash
sudo apt update
sudo apt install -y build-essential clang llvm llvm-dev libclang-dev dos2unix
```

---

## How to Build and Run

### 1. Clone the Repository

```bash
git clone https://github.com/ShettyAish19/Inline-Assembly-Validator.git
cd Inline-Assembly-Validator
```

---

### 2. Build the Validator

Compile the C++ validation engine.

```bash
# Set execution permissions
chmod +x build.sh run.sh

# Convert Windows line endings (if required)
dos2unix build.sh run.sh

# Build project
./build.sh
```

### Expected Output

```text
Building the Inline Assembly Validator...
Build successful! Created binary './validator'
```

---

## Running the Validator

### Test on Valid Code (SUCCESS Cases)

Run validation on syntactically correct x86-64 inline assembly.

```bash
./run.sh testcases/test_good.c
```

### Expected Output

```text
1. Compiling testcases/test_good.c to LLVM IR...
2. Running Validator on generated LLVM IR...

Validating: movl %eax, %ebx -> [PASS] Instruction 'movl' is valid.
Validating: addl %eax, %ebx -> [PASS] Instruction 'addl' is valid.
Validating: subl %0, %eax -> [PASS] Instruction 'subl' is valid.
Validating: push %rax -> [PASS] Instruction 'push' is valid.
Validating: pop %rbx -> [PASS] Instruction 'pop' is valid.
Validating: ret -> [PASS] Instruction 'ret' is valid.
```

---

### Test on Invalid Code (FAILURE Cases)

Run validation on faulty assembly instructions.

```bash
./run.sh testcases/test_bad.c
```

### Expected Output

```text
1. Compiling testcases/test_bad.c to LLVM IR...
2. Running Validator on generated LLVM IR...

Validating: fakeinstr %eax -> [ERROR] Unknown instruction: fakeinstr
Validating: movl $1, %wrongreg -> [ERROR] Invalid or unsupported register: %wrongreg
Validating: addl %eax -> [ERROR] 'addl' expects 2 operands, found 1
Validating: push %eax, %ebx -> [ERROR] 'push' expects 1 operands, found 2
Validating: ret %eax -> [ERROR] 'ret' expects 0 operands, found 1
```

---

## Project Demo / Results

### Build Successful

![Build Output](results/build_output.png)

### Valid Assembly Test Results

![Valid Test Results](results/test_good_output.png)

### Invalid Assembly Test Results

![Invalid Test Results](results/test_bad_output.png)

> Replace the image filenames above with your actual screenshot names inside the `results/` folder.

---

## Technologies Used

* **C++**
* **LLVM IR**
* **Clang Compiler**
* **Shell Scripting (Bash)**
* **Static Analysis Concepts**
* **x86-64 Inline Assembly**

---

## Use Cases

* Compiler Design Learning
* Static Analysis Research
* LLVM IR Understanding
* Assembly Language Education
* Early Error Detection in Inline Assembly

---

## Limitations

* Supports **x86-64 inline assembly only**
* Focused on **syntactic and semantic validation**
* Does not execute assembly code
* Limited instruction coverage (extendable)

---

## Future Enhancements

* Support for additional x86-64 instructions
* Multi-architecture support (ARM, RISC-V)
* Advanced semantic validation
* Graphical reporting dashboard
* LLVM Pass integration

---

## Contributors

**1RV23CS022 Aishwarya Shetty**

**1RV23CS013 Ackshaya Keerthi G**

Project Developer

---

## License

This project is intended for **educational and research purposes**.
