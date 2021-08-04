#include <iostream>
#include "parser/parser.h"
#include "coder/coder.h"

const char errArgFormat[] = "Only excepts arguments format [vm_translator.cc <Prog.vm>]";
int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << errArgFormat << std::endl;
    return -1;
  }
  // n2t::Parser parser;
  return 0;
}
