#include <gtest/gtest.h>

#include "parser.h"

namespace n2t {

TEST(parser_test, hasMoreCommands_exists) {
  std::istringstream command("push constant 7");
  Parser parser(command);
  EXPECT_TRUE(parser.hasMoreCommands());
  EXPECT_TRUE(parser.hasMoreCommands());  // ensure streampos hasn't moved
}

TEST(parser_test, hasMoreCommands_blank) {
  std::istringstream blank("");
  Parser parser(blank);
  EXPECT_FALSE(parser.hasMoreCommands());
}

TEST(parser_test, hasMoreCommands_whitespace) {
  std::istringstream whitespace("\t\n\r\f\v");
  Parser parser(whitespace);
  EXPECT_FALSE(parser.hasMoreCommands());
}

TEST(parser_test, hasMoreCommands_comment) {
  std::istringstream comment("// a comment");
  Parser parser(comment);
  EXPECT_FALSE(parser.hasMoreCommands());
}

}  // namespace n2t
