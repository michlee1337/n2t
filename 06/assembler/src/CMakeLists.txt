## LIBRARIES

add_library(
  symboltable
  symboltable/symboltable.h
  symboltable/symboltable.cc
)

add_library(
  parser
  parser/parser.h
  parser/parser.cc
)

add_library(
  translator
  translator/translator.h
  translator/translator.cc 
)

add_library(
  assembler
  assembler/assembler.h
  assembler/assembler.cc
)

target_include_directories(symboltable PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(parser PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(translator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(assembler PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

## TESTING ##

add_executable(
  translator_test
  translator/translator_test.cc
)

target_link_libraries(
  translator_test
  PUBLIC gtest_main
  PUBLIC translator
)

add_test(
  NAME translator_test
  COMMAND translator_test
)
