#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <ostream>
#include <queue>
#include <random>
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

bool cmp(int a, int b) { return a > b; }

int GetRandInt(int min_, int max_) {
  std::random_device rd;
  std::mt19937 rng(rd());
  std::uniform_int_distribution<int> uni(min_, max_);
  auto random_integer = uni(rng);
  return random_integer;
}

int main(int argc, char** argv) {
  //
  //
  //

  const int length = 100;
  const int max_ = 10000;
  const int min_ = -10000;

  vector<int> nums;
  vector<int> copy;

  for (int i = 0; i < length; i++) {
    int num = GetRandInt(min_, max_);
    nums.push_back(num);
    copy.push_back(num);
  }

  ShuffleQuickSort<int>::QuickSort(nums);

  std::sort(copy.begin(), copy.end());

  for (int i = 0; i < length; i++) {
    if (nums[i] != copy[i]) {
      cout << "err" << endl;
    }
  }
}
