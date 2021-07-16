#ifndef NAND2TETRIS_ASSEMBLER
#define NAND2TETRIS_ASSEMBLER

#include <string>
#include <iostream>
#include <fstream>
#include <bitset>

namespace n2t {

class Assembler {

public:
    int assemble(const std::string asm_file);
};

}

#endif