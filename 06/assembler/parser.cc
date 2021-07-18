#include "parser.h"

namespace n2t {

Parser::Parser(std::string asm_file) {
    asm_file_.open(asm_file);
    cur_line_number_ = 0;
};

bool Parser::get_next() {
    while (std::getline(asm_file_, cur_line_)) {
        ++cur_line_number_;
        if (!isBlank() && !isComment()) {
            return true;
        }
    }
    return false;
};

CommandType Parser::commandType() {
    if (cur_line_[0] == '@') {
        return A_COMMAND;
    }
    return C_COMMAND;
};

std::string Parser::addr() {
    if (commandType() != A_COMMAND) {
        throw "Command is not an A command";
    }
    return cur_line_.substr(1, std::string::npos);
};

std::string Parser::dest() {
    if (commandType() != C_COMMAND) {
        throw "Command is not an C command";
    }
    std::size_t i = cur_line_.find("=");
    if (i == std::string::npos) {
        return "";
    }
    return cur_line_.substr(0, i);
};

std::string Parser::comp() {
    if (commandType() != C_COMMAND) {
        throw "Command is not an C command";
    }
    std::size_t s = cur_line_.find("=");
    std::size_t e = cur_line_.find(";");
    if (s == std::string::npos) {
        s = 0;
    } else {
        s += 1;
    }
    if (e == std::string::npos) {
        e = cur_line_.length()-1;
    }
    return cur_line_.substr(s, e-s);
};

std::string Parser::jump() {
    if (commandType() != C_COMMAND) {
        throw "Command is not an C command";
    }
    std::size_t i = cur_line_.find(";");
    if (i == std::string::npos) {
        return "";
    }
    return cur_line_.substr(i+1, cur_line_.length()-i-2);
};

int Parser::cur_line_number() {
    return cur_line_number_;
};

std::string Parser::cur_line() {
    return cur_line_;
};

bool Parser::isComment() {
    return (cur_line_[0] == '/' && cur_line_[1] == '/');
};

bool Parser::isBlank() {
    return std::all_of(cur_line_.begin(),cur_line_.end(),isspace);
};

}