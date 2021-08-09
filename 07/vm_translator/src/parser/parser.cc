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

}  // namespace n2t