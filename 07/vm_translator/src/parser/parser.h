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
  std::streampos pos_;
  bool isCommand();

 public:
  explicit Parser(std::istream &instream) : in_(instream) {};
  bool hasMoreCommands();
  void advance();
  CommandType commandType();
  std::string arg1();
  std::string arg2();
  std::string cur_line();
};

}  // namespace n2t

#endif  // PROJECTS_07_VM_TRANSLATOR_SRC_PARSER_PARSER_H_