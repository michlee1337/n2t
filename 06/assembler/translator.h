#ifndef NAND2TETRIS_TRANSLATOR
#define NAND2TETRIS_TRANSLATOR

#include <string>
#include <unordered_map>
#include <bitset>
#include <fstream>

namespace n2t {

class Translator {

private:
    static inline std::unordered_map< std::string, std::bitset<16> > dest_map_ = {
        {"", 0b0000000000000000},
        {"M", 0b0000000000001000},
        {"D", 0b0000000000010000},
        {"MD", 0b0000000000011000},
        {"A", 0b0000000000100000},
        {"AM", 0b0000000000101000},
        {"AD", 0b0000000000110000},
        {"AMD", 0b0000000000111000}
    };

    static inline std::unordered_map< std::string, std::bitset<16> > comp_map_ = {
        {"0", 0b00000101010000000},
        {"1", 0b00000111111000000},
        {"-1", 0b00000111010000000},
        {"D", 0b00000001100000000},
        {"A", 0b00000110000000000},
        {"!D", 0b00000001101000000},
        {"!A", 0b00000110001000000},
        {"-D", 0b00000001111000000},
        {"-A", 0b00000110011000000},
        {"D+1", 0b0000011111000000},
        {"A+1", 0b00000110111000000},
        {"D-1", 0b00000001110000000},
        {"A-1", 0b00000110010000000},
        {"D+A", 0b00000000010000000},
        {"D-A", 0b00000010011000000},
        {"A-D", 0b00000000111000000},
        {"D&A", 0b00000000000000000},
        {"D|A", 0b00000010101000000}
    };

    static inline std::unordered_map< std::string, std::bitset<16> > jump_map_ = {
        {"", 0b0000000000000000},
        {"JGT", 0b0000000000000001},
        {"JEQ", 0b0000000000000010},
        {"JGE", 0b0000000000000011},
        {"JLT", 0b0000000000000100},
        {"JNE", 0b0000000000000101},
        {"JLE", 0b0000000000000110},
        {"JMP", 0b0000000000000111}
    };


public:
    std::bitset<16> addr(std::string addr_asm);
    std::bitset<16> dest(std::string dest_asm);
    std::bitset<16> comp(std::string comp_asm);
    std::bitset<16> jump(std::string jump_asm);
};

}

#endif