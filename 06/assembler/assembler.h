#ifndef NAND2TETRIS_ASSEMBLER
#define NAND2TETRIS_ASSEMBLER

#include <string>
#include <unordered_map>

#include "parser.h"
#include "translator.h"


namespace n2t {

class Assembler {

private:
    // int line_number;
    // std::string parse_dest(std::string asm_dest);
    // std::string parse_comp(std::string asm_dest);
    // std::map< std::string, std::string > dest_map = {
    //     "M" = "001",
    //     "D" = "010",
    //     "MD" = "011",
    //     "A" = "100",
    //     "AM" = "101",
    //     "AD" = "110",
    //     "AMD" = "111"
    // }

public:
    int assemble(const std::string asm_file);
};

}

#endif