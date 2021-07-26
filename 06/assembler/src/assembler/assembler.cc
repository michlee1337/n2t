#include "parser/parser.h"
#include "translator/translator.h"

#include "assembler/assembler.h"

namespace n2t {

int Assembler::assemble(std::string asm_file) {

    // first pass to initialize symbol table on construction
    Parser parser(asm_file);
    Translator translator;

    std::ofstream hack_file;
    hack_file.open(asm_file.substr(0, asm_file.find(".asm")) + ".hack");


    // get symbols
    while (parser.get_next()) {
        switch (parser.commandType()) {
            case A_COMMAND: {
                hack_file << translator.addr(parser.addr()) << std::endl;
                break;
            }
            case C_COMMAND: {
                std::bitset<16> dest(translator.dest(parser.dest()));
                std::bitset<16> comp(translator.comp(parser.comp()));
                std::bitset<16> jump(translator.jump(parser.jump()));
                std::bitset<16> inst(dest | comp | jump);
                hack_file << inst << std::endl;
                break;
            }
        }
    }
    return 0;
}

}
