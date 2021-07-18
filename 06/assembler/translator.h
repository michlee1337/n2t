#ifndef NAND2TETRIS_TRANSLATOR
#define NAND2TETRIS_TRANSLATOR

#include <string>
#include <unordered_map>
#include <bitset>

namespace n2t {

class Translator {

private:
    static inline std::unordered_map< std::string, std::bitset<16> > dest_map_ = {
        {"", 0b1110000000000000},
        {"M", 0b1110000000001000},
        {"D", 0b1110000000010000},
        {"MD", 0b1110000000011000},
        {"A", 0b1110000000100000},
        {"AM", 0b1110000000101000},
        {"AD", 0b1110000000110000},
        {"AMD", 0b1110000000111000}
    };

    static inline std::unordered_map< std::string, std::bitset<16> > comp_map_ = {
        {"0", 0b11100101010000000},
        {"1", 0b11100111111000000},
        {"-1", 0b11100111010000000},
        {"D", 0b11100001100000000},
        {"A", 0b11100110000000000},
        {"!D", 0b11100001101000000},
        {"!A", 0b11100110001000000},
        {"-D", 0b11100001111000000},
        {"-A", 0b11100110011000000},
        {"D+1", 0b1110011111000000},
        {"A+1", 0b11100110111000000},
        {"D-1", 0b11100001110000000},
        {"A-1", 0b11100110010000000},
        {"D+A", 0b11100000010000000},
        {"D-A", 0b11100010011000000},
        {"A-D", 0b11100000111000000},
        {"D&A", 0b11100000000000000},
        {"D|A", 0b11100010101000000},
        {"M", 0b1111110000000000},
        {"!M", 0b1111110001000000},
        {"-M", 0b1111110011000000},
        {"M+1", 0b1111110111000000},
        {"M-1", 0b1111110010000000},
        {"D+M", 0b11110000010000000},
        {"D-M", 0b11110010011000000},
        {"M-D", 0b11110000111000000},
        {"D&M", 0b11110000000000000},
        {"D|M", 0b11110010101000000},

    };

    static inline std::unordered_map< std::string, std::bitset<16> > jump_map_ = {
        {"", 0b1110000000000000},
        {"JGT", 0b1110000000000001},
        {"JEQ", 0b1110000000000010},
        {"JGE", 0b1110000000000011},
        {"JLT", 0b1110000000000100},
        {"JNE", 0b1110000000000101},
        {"JLE", 0b1110000000000110},
        {"JMP", 0b1110000000000111}
    };


public:
    std::bitset<16> addr(std::string addr_asm);
    std::bitset<16> dest(std::string dest_asm);
    std::bitset<16> comp(std::string comp_asm);
    std::bitset<16> jump(std::string jump_asm);
};

}

#endif