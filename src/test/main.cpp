#include <gtest/gtest.h>

#include <iostream>
#include <queue>

#include "../bipointer/bipointer.h"
#include "../design/design.h"
#include "../string/string.h"

using namespace std;
using namespace design;

using namespace mystring;

TEST(design_test, bilist) {
  EXPECT_EQ(isNumber("123"), true);
  EXPECT_EQ(isNumber("1  "), true);
  EXPECT_EQ(isNumber("  3"), true);

  EXPECT_EQ(isNumber("  3  "), true);
  EXPECT_EQ(isNumber("12.3"), true);
  EXPECT_EQ(isNumber(".123"), true);

  EXPECT_EQ(isNumber("123."), false);
  EXPECT_EQ(isNumber("e123"), false);
  EXPECT_EQ(isNumber("123e"), false);
  EXPECT_EQ(isNumber("123"), true);
  EXPECT_EQ(isNumber("123"), true);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}