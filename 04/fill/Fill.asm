// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed.
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

@RESET
0; JEQ

(RESET)
  // set counter = 8192
  @8192
  D=A
  @counter
  M=D

  // set addr = SCREEN
  @SCREEN
  D=A
  @addr
  M=D

  // get press
  @KBD
  D=M
  @WHITE
  D; JEQ

(BLACK) // make black
  // make cur word black
  @addr
  A=M
  M=-1

  // update counter
  @counter
  M=M-1

  // update word address
  @addr
  M=M+1

  // end if counter == 0
  @counter
  D=M
  @RESET
  D; JEQ

  // loop
  @BLACK
  0;JMP


(WHITE) // make white
  // make cur word wite
  @addr
  A=M
  M=0

  // update counter
  @counter
  M=M-1

  // update word address
  @addr
  M=M+1

  // end if counter == 0
  @counter
  D=M
  @RESET
  D; JEQ

  // loop
  @WHITE
  0;JMP

(END)
  @END
  0; JMP
