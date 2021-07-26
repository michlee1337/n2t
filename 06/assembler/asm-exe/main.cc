#include <iostream>
#include "assembler/assembler.h"

const char errArgFormat[] = "Only excepts arguments format [asm.cc <Prog.asm>]";
int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << errArgFormat << std::endl;
    return -1;
  }
  // assembler.process(std::string(argv[1]));
  n2t::Assembler assembler;
  assembler.assemble(std::string(argv[1]));

  return 0;
}
