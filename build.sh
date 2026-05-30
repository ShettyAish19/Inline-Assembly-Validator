#!/bin/bash
echo "Building the Inline Assembly Validator..."
g++ -std=c++17 -O3 src/validator.cpp -o validator
if [ $? -eq 0 ]; then
    echo "Build successful! Created './validator'"
else
    echo "Build failed!"
    exit 1
fi