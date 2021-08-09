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

}  // namespace n2t