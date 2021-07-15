#ifndef NAND2TETRIS_PARSER
#define NAND2TETRIS_PARSER

#include <string>

namespace n2t {

enum CommandType (A_COMMAND, C_COMMAND);

class Parser {

private:
	std::ifstream 	f_;
    std::unordered_map< std::string, int > symbol_table_;
	int current_line_number_;

public:
	Parser(std::istream& is);  // parse symbols on construction

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