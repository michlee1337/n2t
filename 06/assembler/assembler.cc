#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

#include "assembler.h"

namespace n2t {

int Assembler::process(std::string asm_file) {
    std::ifstream file(asm_file);

    // first pass to initialize symbol table on construction
    Parser parser(file);
    Translater translator;

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
        // // get symbols
        // // ignore comment and white spcae
        // if (line.substr(0, 2) == "//" or std::all_of(
        //     line.begin(),line.end(), isspace)) {
        //     continue;
        // } else if (line[0] != "@") {
        //     process_c(&line);
        // } else if (std::isdigit(line[1])) {
        //     process_a(&line);
        // } else if (line[1] == "(") {
        //     process_label(&line);
        // } else {
        //     process_value(&line);
        // }
    }
    std::cout << "done" << std::endl;
    return 0;
}

// int Assembler::process_a(std:string& line) {
//     line_numer ++;
//     int address = std::stoi(line.substr(1,15));
//     std::cout << line_number << line << " -> " << address << std::endl;
// }

// int Assembler::process_c(std:string& line) {

//     // handle comp
//     // handle dest 
//     dest = parse_dest(line);


//     std::cout << line_number << line << " -> " << address << std::endl;
// }

// int Assembler::process_label(std:string& line) {
//     std::cout << "SYM: " << line << std::endl;
//     // value
//     // label
//     if (line[1]) == 
// }

// int Assembler::process_value(std:string& line) {
//     std::cout << "SYM: " << line << std::endl;
//     // value
//     // label
//     if (line[1]) == 
// }


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