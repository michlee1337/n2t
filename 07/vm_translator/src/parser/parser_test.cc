#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <iostream>

#include "parser.h"

namespace n2t {
class ParserTest : public ::testing::Test {
 public:
  std::istringstream dummy_in_;
  Parser parser_ = Parser(dummy_in_);
};

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

TEST_F(ParserTest, advance_simple) {
  dummy_in_.str("push constant 7\npush constant 9\neq");
  parser_.advance();
  EXPECT_EQ(parser_.cur_line(), "push constant 7");
  parser_.advance();
  EXPECT_EQ(parser_.cur_line(), "push constant 9");
  parser_.advance();
  EXPECT_EQ(parser_.cur_line(), "eq");
}

TEST_F(ParserTest, advance_comments) {
  dummy_in_.str("push constant 7\n//ignore me\neq");
  parser_.advance();
  EXPECT_EQ(parser_.cur_line(), "push constant 7");
  parser_.advance();
  EXPECT_EQ(parser_.cur_line(), "eq");
}

TEST_F(ParserTest, advance_whitespace) {
  dummy_in_.str("push constant 7\n\t\t\n\neq");
  parser_.advance();
  EXPECT_EQ(parser_.cur_line(), "push constant 7");
  parser_.advance();
  EXPECT_EQ(parser_.cur_line(), "eq");
}

TEST_F(ParserTest, advance_inline_comments) {
  dummy_in_.str("push constant 7\npush constant 9 // comment \n eq");
  parser_.advance();
  EXPECT_EQ(parser_.cur_line(), "push constant 7");
  parser_.advance();
  EXPECT_EQ(parser_.cur_line(), "push constant 9");
  parser_.advance();
  EXPECT_EQ(parser_.cur_line(), "eq");
}

TEST_F(ParserTest, advance_trailing_whitespace) {
  dummy_in_.str("push constant 7\n    push constant 9    \n eq");
  parser_.advance();
  EXPECT_EQ(parser_.cur_line(), "push constant 7");
  parser_.advance();
  EXPECT_EQ(parser_.cur_line(), "push constant 9");
  parser_.advance();
  EXPECT_EQ(parser_.cur_line(), "eq");
}

}  // namespace n2t
