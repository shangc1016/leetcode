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
#include "bipointer/bipointer.h"
#include "design/design.h"
#include "dp/dp.h"
#include "hash/hash.h"
#include "list/list.h"
#include "slidewindow/slidewindow.h"
#include "sort/sort.h"
#include "stack/stack.h"
#include "string/string.h"
#include "tree/tree.h"

using namespace std;
using namespace design;
using namespace bipointer;
using namespace binarytree;

using namespace sort;

int main(int argc, char** argv) {
  vector<int> nums = {3, 12, 34, 23, 4, 234, 23, 45, 2};
  QuickSort::quickSort(nums);
  for (int val : nums) {
    cout << val << endl;
  }

  cout << findKthLargest(nums, 1) << endl;
}
