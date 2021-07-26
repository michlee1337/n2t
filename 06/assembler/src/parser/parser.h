#ifndef PROJECTS_06_ASSEMBLER_SRC_PARSER_PARSER_H_
#define PROJECTS_06_ASSEMBLER_SRC_PARSER_PARSER_H_

#include <string>
#include <unordered_map>
#include <fstream>

#include "symboltable/symboltable.h"

namespace n2t {

enum CommandType {A_COMMAND, C_COMMAND};

class Parser {
 private:
  std::ifstream asm_file_;
  SymbolTable symbol_table_;
  std::string cur_line_;
  bool isSymbol();
  bool isLabel();
  bool isComment();
  bool isBlank();
  void trim();

 public:
  explicit Parser(std::string asm_file);  // parse symbols on construction

  // parsed elements of current command
  std::string addr();
  std::string dest();
  std::string comp();
  std::string jump();

  bool get_next();  // returns False if end of file
  CommandType commandType();
  std::string cur_line();
};

}  // namespace n2t

#endif  // PROJECTS_06_ASSEMBLER_SRC_PARSER_PARSER_H_
