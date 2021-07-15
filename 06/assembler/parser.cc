#include "assembler.h"

namespace n2t {

Parser::Parser(std::istream& is) {
    // TODO: PARSE SYMBOLS
    current_line_number_(0);
    f_(is);
}

bool Parser::get_next() {
    while (std.getline(f_, current_line_) {
        ++current_line_number_;
        if (!line.empty() && !isComment(line)) {
            return True;
        }
    }
    return False
}


}