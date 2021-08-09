#ifndef PROJECTS_07_VM_TRANSLATOR_SRC_CODER_CODER_H_
#define PROJECTS_07_VM_TRANSLATOR_SRC_CODER_CODER_H_

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

class Coder {
 private:
  std::ostream& of_;

 public:
  Coder (std::ostream &outstream) : of_(outstream) {};
  int writeArithmetic();
  int writePushPop();
  int close();
};

}  // namespace n2t

#endif  // PROJECTS_07_VM_TRANSLATOR_SRC_CODER_CODER_H_