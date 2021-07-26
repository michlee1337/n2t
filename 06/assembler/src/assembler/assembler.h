#ifndef PROJECTS_06_ASSEMBLER_SRC_ASSEMBLER_ASSEMBLER_H_
#define PROJECTS_06_ASSEMBLER_SRC_ASSEMBLER_ASSEMBLER_H_

#include <string>
#include <fstream>
#include <bitset>

namespace n2t {

class Assembler {
 public:
  int assemble(const std::string asm_file);
};

}

#endif  // PROJECTS_06_ASSEMBLER_SRC_ASSEMBLER_ASSEMBLER_H_
