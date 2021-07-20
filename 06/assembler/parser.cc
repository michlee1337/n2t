#include "parser.h"

namespace n2t {

Parser::Parser(std::string asm_file) {
    asm_file_.open(asm_file);

    // parse by line
    symbol_table_ = SymbolTable();
    int line_num = 0;
    while (std::getline(asm_file_, cur_line_)) {      
        trim();
        if (isLabel()) {
            symbol_table_.RegisterLabel(cur_line_.substr(1, cur_line_.length()-2), line_num);
        } else if (isSymbol()) {
            symbol_table_.RegisterSymbol(cur_line_.substr(1, cur_line_.length()-1));
             ++line_num;
        } else if(!isBlank() && !isComment()) {
             ++line_num;
        }
    }
    symbol_table_.complete();

    // reset ifstream
    asm_file_.clear();
    asm_file_.seekg(0);
};

bool Parser::get_next() {
    while (std::getline(asm_file_, cur_line_)) {
        trim();
        if (!isBlank() && !isComment() && !isLabel()) {
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
    std::string addr = cur_line_.substr(1, std::string::npos);
    if (isSymbol()) {
        return symbol_table_.value(addr);
    }
    return addr;
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
        e = cur_line_.length();
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
    return cur_line_.substr(i+1, cur_line_.length()-i-1);
};

std::string Parser::cur_line() {
    return cur_line_;
};

bool Parser::isLabel() {
    return (cur_line_[0] == '(');
};

bool Parser::isSymbol() {
    return (commandType() == A_COMMAND && !isdigit(cur_line_[1]));
};


bool Parser::isComment() {
    return (cur_line_[0] == '/' && cur_line_[1] == '/');
};

bool Parser::isBlank() {
    return std::all_of(cur_line_.begin(),cur_line_.end(),isspace);
};

void Parser::trim() {
    // rmv comments
    size_t i = cur_line_.find_first_of('/');
    if (i != std::string::npos) {
        cur_line_.erase(i);
    }

    // rmv whitespace
    const char* whitespace = " \t\n\r\f\v";
    cur_line_.erase(0, cur_line_.find_first_not_of(whitespace));
    cur_line_.erase(cur_line_.find_last_not_of(whitespace) + 1);
    return;
}

}