// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Put your code here.

///////////////
// D = R0
// R3 = D

// i = 0
// 2 = 0
// while i < R1
//   2 += R0
//   i += 1
// end
///////////////


@0
D=M

@2
M=0

@index
M=0

(LOOP)
  @index
  D=M
  @1
  D=D-M
  @END
  D; JEQ
  @0 // D=R0
  D=M
  @2 // 2+=D
  M=M+D
  @index
  M=M+1
  // i += 1
  @LOOP
  0; JMP

(END)
  @END
  0; JMP
