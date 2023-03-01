#include <cassert>
#include <cstddef>
#include <cstdio>
#include <functional>
#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <utility>
#include <vector>

#include "array/array.h"
#include "backtracing/backtracing.h"
#include "binarytree/binarytree.h"
#include "hash/hash.h"
#include "list/list.h"
#include "stack/stack.h"
#include "string/istring.h"
#include "tree/tree.h"
#include "dp/dp.h"

using namespace std;
using namespace leetcode;

int main(int argc, char** argv) {
  cout << climbStairsII(10, 2) << endl;
  cout << climbStairs(10) << endl;

  return 0;
}
