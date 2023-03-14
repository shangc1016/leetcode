#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <ostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

#include "array/array.h"
#include "backtracing/backtracing.h"
#include "binarytree/binarytree.h"
#include "design/design.h"
#include "dp/dp.h"
#include "hash/hash.h"
#include "list/list.h"
#include "slidewindow/slidewindow.h"
#include "stack/stack.h"
#include "string/istring.h"
#include "tree/tree.h"

using namespace std;
// using namespace leetcode;

using namespace design;

int main(int argc, char** argv) {
  unordered_set<int> uset;
  uset.insert(1);
  uset.insert(2);
  uset.insert(3);
  uset.insert(4);
  uset.insert(5);
  uset.insert(6);
  for (auto item : uset) {
    cout << item << endl;
  }
}
