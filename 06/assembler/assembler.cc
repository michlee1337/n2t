#include "parser.h"
#include "translator.h"

#include "assembler.h"

namespace n2t {

int Assembler::assemble(std::string asm_file) {

    // first pass to initialize symbol table on construction
    Parser parser(asm_file);
    Translator translator;

    // get symbols
    std::string line;
    while (parser.get_next()) {
        switch (parser.commandType()) {
            case A_COMMAND:
                std::cout << std::bitset<16>(parser.addr()) << std::endl;
                break;
            
            case C_COMMAND: 
                std::bitset<16> dest(translator.dest(parser.dest()));
                std::bitset<16> comp(translator.comp(parser.comp()));
                std::bitset<16> jump(translator.jump(parser.jump()));
                std::bitset<16> inst(dest | comp | jump);
                std::cout << inst << std::endl;
                break;
        }
    }
    std::cout << "done" << std::endl;
    return 0;
}

// // private methods
// std::string Assembler::parse_comp(std:string& line) {
//     std::string asm_comp = line.substr(line.find("="), line.find(";"));
//     return dest_map[asm_dest];
// }
// std::string Assembler::parse_dest(std:string& line) {
//     if (line.find("=") == std::string::npos) {
//         return "000";
//     }
//     std::string asm_dest = line.substr(1, line.find(" "));
//     return dest_map[asm_dest];
// }
}