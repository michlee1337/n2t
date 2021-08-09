#include "parser.h"

namespace n2t {

bool Parser::hasMoreCommands() {
  while (std::getline(in_, cur_line_)) {
    if (isCommand()) {
      in_.seekg(pos_, std::ios_base::beg);
      return true;
    } else {
      pos_ = in_.tellg();
    }
  }
  return false;
}

void Parser::advance() {
  do {
    getline(in_, cur_line_);
  }
  while (!isCommand());
  
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

CommandType Parser::commandType() {
  const std::string& first = cur_line_.substr(0, cur_line_.find(" "));
  if (first == "push") {
    return CommandType::C_PUSH;
  } else if (first == "pop") {
    return CommandType::C_POP;
  } else {
    return CommandType::C_ARITHMETIC;
  }
  // TODO: add other commandtypes
}

}  // namespace n2t