#include <gtest/gtest.h>

#include "coder.h"

TEST(coder_test, dummy) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}
