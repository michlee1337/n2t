#ifndef NAND2TETRIS_PARSER
#define NAND2TETRIS_PARSER

#include <string>
#include <unordered_map>
#include <fstream>

namespace n2t {

enum CommandType {A_COMMAND, C_COMMAND};

class Parser {

private:
	std::ifstream 	asm_file_;
    std::unordered_map< std::string, int > symbol_table_;
	int cur_line_number_;
	std::string cur_line_;
    bool isComment();
    bool isBlank();

public:
	Parser(std::string asm_file);  // parse symbols on construction

    // parsed elements of current command
    std::string addr();
    std::string dest();
    std::string comp();
    std::string jump();

    bool get_next();  // returns False if end of file
    CommandType commandType();
    int cur_line_number();
    std::string cur_line();
};

}

#endif