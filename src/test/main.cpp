#include <gtest/gtest.h>

#include <iostream>
#include <queue>

#include "../design/design.h"

#include "../bipointer/bipointer.h"

using namespace std;
using namespace design;

TEST(design_test, bilist) {
  ListNode* list = nullptr;
  list = InsertTail(list, NewListNode(1, 1));
  list = InsertTail(list, NewListNode(2, 1));
  list = InsertTail(list, NewListNode(3, 1));
  list = InsertTail(list, NewListNode(4, 1));

  TraverseNode(list);

}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}