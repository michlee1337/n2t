#include "parser.h"

namespace n2t {

Parser::Parser(std::string asm_file) {
    asm_file_.open(asm_file);
    cur_line_number_ = 0;
}

bool Parser::get_next() {
    while (std::getline(asm_file_, cur_line_)) {
        ++cur_line_number_;
        if (!isBlank() && !isComment()) {
            return true;
        }
    }
    return false;
}

    CommandType Parser::commandType() {
        if (cur_line_[0] == '@') {
            return A_COMMAND;
        }
        return C_COMMAND;
    }

    std::string Parser::addr() {
        return "";
    };

    std::string Parser::dest() {
        return "";
    };

    std::string Parser::comp() {
        return "";
    };

    std::string Parser::jump() {
        return "";
    };

int Parser::cur_line_number() {
    return cur_line_number_;
}

std::string Parser::cur_line() {
    return cur_line_;
}

bool Parser::isComment() {
    return (cur_line_[0] == '/' && cur_line_[1] == '/');
}

bool Parser::isBlank() {
    return (std::all_of(cur_line_.begin(),cur_line_.end(),isspace));
}

}