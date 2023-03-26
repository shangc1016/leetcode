#include <gtest/gtest.h>

#include <iostream>
#include <queue>

#include "../bipointer/bipointer.h"
#include "../design/design.h"
#include "../sort/sort.h"
#include "../string/string.h"

using namespace std;
using namespace design;

using namespace mystring;

TEST(design_test, DISABLED_bilist) {
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

TEST(SortTest, RingQueueTest) {
  int capacity = 10;

  RingQueue queue(capacity);

  for (int i = 0; i < capacity; i++) {
    EXPECT_TRUE(queue.Insert(i));
  }

  EXPECT_EQ(0, queue.front());
  queue.Pop();
  EXPECT_EQ(1, queue.front());

  // EXPECT_TRUE(queue.Insert(123));
  // EXPECT_FALSE(queue.Insert(1234));
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}