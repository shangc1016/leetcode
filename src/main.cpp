// #include <algorithm>
// #include <cassert>
// #include <cstddef>
// #include <cstdint>
// #include <cstdio>
// #include <functional>
// #include <iostream>
// #include <iterator>
// #include <list>
// #include <map>
// #include <memory>
// #include <ostream>
// #include <queue>
// #include <random>
// #include <string>
// #include <unordered_set>
// #include <utility>
// #include <vector>

// #include "array/array.h"
// #include "backtracing/backtracing.h"
// #include "binarytree/binarytree.h"
// #include "bipointer/bipointer.h"
// #include "design/design.h"
// #include "dp/dp.h"
// #include "hash/hash.h"
// #include "list/list.h"
// #include "slidewindow/slidewindow.h"
// #include "sort/sort.h"
// #include "stack/stack.h"
// #include "string/string.h"
// #include "tree/tree.h"

// using namespace std;
// using namespace design;
// using namespace bipointer;
// using namespace binarytree;

// using namespace sort;

// bool cmp(int a, int b) { return a > b; }

// int GetRandInt(int min_, int max_) {
//   std::random_device rd;
//   std::mt19937 rng(rd());
//   std::uniform_int_distribution<int> uni(min_, max_);
//   auto random_integer = uni(rng);
//   return random_integer;
// }

// int main(int argc, char** argv) {
//   //
//   //
//   //

//   const int length = 100;
//   const int max_ = 10000;
//   const int min_ = -10000;

//   vector<int> nums;
//   vector<int> copy;

//   for (int i = 0; i < length; i++) {
//     int num = GetRandInt(min_, max_);
//     nums.push_back(num);
//     copy.push_back(num);
//   }

//   ShuffleQuickSort<int>::QuickSort(nums);

//   std::sort(copy.begin(), copy.end());

//   for (int i = 0; i < length; i++) {
//     if (nums[i] != copy[i]) {
//       cout << "err" << endl;
//     }
//   }
// }

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   * 比较版本号
   * @param version1 string字符串
   * @param version2 string字符串
   * @return int整型
   */

  void parser(string &version, vector<string> &vec) {
    int pos;
    while ((pos = version.find('.')) > 0) {
      vec.push_back(version.substr(0, pos));
      version = version.substr(pos + 1);
    }
    vec.push_back(version);
  }

  int comp(string &a, string &b) {
    if (a == b)
      return 0;
    else if (a > b)
      return 1;
    else
      return -1;
  }

  int compare(string version1, string version2) {
    vector<string> v1;
    vector<string> v2;

    parser(version1, v1);
    parser(version2, v2);

    // for (auto item : v1) cout << item << endl;
    // cout << endl;
    // for (auto item : v2) cout << item << endl;

    int size = min(v1.size(), v2.size());
    for (int i = 0; i < size; i++) {
      int result = comp(v1[i], v2[i]);
      if (result != 0) return result;
    }
    if (v1.size() > v2.size())
      return 1;
    else if (v1.size() < v2.size())
      return -1;
    else
      return 0;
  }
};

int main() {
  Solution so;
  cout << so.compare("1.1", "1.01") << endl;
  return 0;
}