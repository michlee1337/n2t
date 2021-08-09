#ifndef PROJECTS_07_VM_TRANSLATOR_SRC_PARSER_PARSER_H_
#define PROJECTS_07_VM_TRANSLATOR_SRC_PARSER_PARSER_H_

#include <string>
#include <fstream>

namespace n2t {

enum CommandType {C_ARITHMETIC,
                  C_PUSH,
                  C_POP,
                  C_LABEL,
                  C_GOTO,
                  C_IF,
                  C_FUNCTION,
                  C_RETURN,
                  C_CALL};

class Parser {
 private:
  std::istream& in_;
  std::string cur_line_;

 public:
  explicit Parser(std::istream &instream) : in_(instream) {};
  bool hasMoreCommands();
  void advance();
  CommandType commandType();
  int arg1();
  int arg2();
}

}  // namespace n2t

#endif  // PROJECTS_07_VM_TRANSLATOR_SRC_PARSER_PARSER_H_