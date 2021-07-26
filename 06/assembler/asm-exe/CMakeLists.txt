add_executable(asm-exe main.cc)

target_link_libraries(asm-exe
  PRIVATE symboltable
  PRIVATE parser
  PRIVATE translator
  PRIVATE assembler
)
