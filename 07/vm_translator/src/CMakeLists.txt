## LIBRARIES

add_library(
  parser
  parser/parser.h
  parser/parser.cc
)

add_library(
  coder
  coder/coder.h
  coder/coder.cc
)


target_include_directories(coder PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(parser PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

## TESTING ##

add_executable(
  parser_test
  parser/parser_test.cc
)

target_link_libraries(
  parser_test
  PUBLIC gtest_main
  PUBLIC parser
)

add_test(
  NAME parser_test
  COMMAND parser_test
)
