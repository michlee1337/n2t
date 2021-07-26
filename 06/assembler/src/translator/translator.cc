#include "translator/translator.h"

namespace n2t {

std::bitset<16> Translator::addr(std::string addr_asm) {
    std::bitset<16> addr(std::stoi(addr_asm));
    return addr;
}

std::bitset<16> Translator::dest(std::string dest_asm) {
    return dest_map_[dest_asm];
}

std::bitset<16> Translator::comp(std::string comp_asm) {
    return comp_map_[comp_asm];
}

std::bitset<16> Translator::jump(std::string jump_asm) {
    return jump_map_[jump_asm];
}

}