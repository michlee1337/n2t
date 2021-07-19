#ifndef NAND2TETRIS_SYMBOLTABLE
#define NAND2TETRIS_SYMBOLTABLE

#include <string>
#include <unordered_map>

#include <iostream>

namespace n2t {


enum SymbolType {LABEL, VARIABLE};

class SymbolTable {

private:
    std::unordered_map< std::string, int > symbol_table_ = {
        {"SCREEN", 16384},
        {"KBD", 24576},
        {"R0", 0},
        {"R1", 1},
        {"R2", 2},
        {"R3", 3},
        {"R4", 4},
        {"R5", 5},
        {"R6", 6},
        {"R7", 7},
        {"R8", 8},
        {"R9", 9},
        {"R10", 10},
        {"R11", 11},
        {"R12", 12},
        {"R13", 13},
        {"R14", 14},
        {"R15", 15}
    };

public:
    void RegisterLabel(std::string label, int line);
    void RegisterSymbol(std::string symbol);
    void complete();
    std::string value(std::string symbol);
};

}

#endif