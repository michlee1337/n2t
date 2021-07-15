#include <iostream>
#include "assembler.h"

int main(int argc, char* argv[])
{
   if (argc != 2) {
      std::cout << "only excepts arguments format [asm.cc <Prog.asm>]" << std::endl;
      return -1;
   }
   // assembler.process(std::string(argv[1]));
   n2t::Assembler assembler;
   assembler.process(std::string(argv[1]));

   return 0;

}