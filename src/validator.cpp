#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>

// 1. Rules Database: Instruction -> Expected Operand Count
std::map<std::string, int> instructionRules = {
    {"movl", 2}, {"addl", 2}, {"subl", 2}, {"imull", 2},
    {"push", 1}, {"pop", 1}, {"ret", 0}
};

// 2. Valid Register Database
std::set<std::string> validRegisters = {
    "%eax", "%ebx", "%ecx", "%edx", "%esi", "%edi", "%esp", "%ebp",
    "%rax", "%rbx", "%rcx", "%rdx", "%rsi", "%rdi", "%rsp", "%rbp"
};

void validateSemantics(const std::vector<std::string>& parts) {
    std::string mnemonic = parts[0];

    // Check 1: Is the instruction known?
    if (instructionRules.find(mnemonic) == instructionRules.end()) {
        std::cout << "[ERROR] Unknown instruction: " << mnemonic << std::endl;
        return;
    }

    // Check 2: Correct number of operands?
    if ((parts.size() - 1) != instructionRules[mnemonic]) {
        std::cout << "[ERROR] '" << mnemonic << "' expects " << instructionRules[mnemonic] 
                  << " operands, found " << (parts.size() - 1) << std::endl;
        return;
    }

    // Check 3: Semantic check for registers
    for (size_t i = 1; i < parts.size(); ++i) {
        if (parts[i][0] == '%') { // If it starts with %, it's a register
            if (validRegisters.find(parts[i]) == validRegisters.end()) {
                std::cout << "[ERROR] Invalid or unsupported register: " << parts[i] << std::endl;
                return;
            }
        }
    }

    std::cout << "[PASS] Instruction '" << mnemonic << "' is valid." << std::endl;
}

void processLine(std::string asm_code) {
    // Clean string: replace commas with space for easier splitting
    std::replace(asm_code.begin(), asm_code.end(), ',', ' ');
    
    std::stringstream ss(asm_code);
    std::string token;
    std::vector<std::string> parts;
    while (ss >> token) parts.push_back(token);

    if (parts.empty()) return;

    std::cout << "Validating: " << asm_code << " -> ";
    validateSemantics(parts);
}

int main() {
    std::ifstream file("test.ll");
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open test.ll" << std::endl;
        return 1;
    }

    while (getline(file, line)) {
        size_t pos = line.find("asm");
        if (pos != std::string::npos) {
            size_t start = line.find("\"", pos);
            size_t end = line.find("\"", start + 1);
            if (start != std::string::npos && end != std::string::npos) {
                processLine(line.substr(start + 1, end - start - 1));
            }
        }
    }
    return 0;
}