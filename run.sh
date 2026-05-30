#!/bin/bash
if [ ! -f "./validator" ]; then
    echo "Error: Validator binary not found. Please run ./build.sh first."
    exit 1
fi

# Use the argument passed, or default to testcases/test_bad.c
TEST_FILE=${1:-"testcases/test_bad.c"}

echo "1. Compiling $TEST_FILE to LLVM IR..."
# This generates 'test.ll' in the current folder where ./validator expects it
clang -S -emit-llvm "$TEST_FILE" -o test.ll

if [ $? -eq 0 ]; then
    echo "2. Running Validator on generated LLVM IR..."
    ./validator
else
    echo "Error compiling C file to LLVM IR."
    exit 1
fi