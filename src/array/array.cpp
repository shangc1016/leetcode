#include "array.h"

#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <utility>

namespace leetcode {
void array() { std::cout << "array" << std::endl; }

// 209. 长度最小的子数组
// 暴力方法超时
// int minSubArrayLen(int target, vector<int>& nums) {

//   int sz = INT_MAX;
//   for (int i = 0; i < nums.size(); i++) {
//     int sum = 0;
//     for (int j = i; j < nums.size(); j++) {
//       sum += nums[j];
//       if (sum >= target && j - i + 1 < sz) {
//         sz = j - i + 1;
//         cout << sz << endl;
//         break;
//       }
//     }
//   }
//   return sz == INT_MAX ? 0 : sz;
// }

// 滑动窗口
int minSubArrayLen(int target, vector<int>& nums) {
  if (nums.size() == 0) return 0;

  int sum = 0;
  int start = 0, end = 0;
  int len = INT_MAX;

  while (end < nums.size()) {
    sum += nums[end];
    while (sum >= target) {
      len = min(len, end - start + 1);
      sum -= nums[start++];
      start++;
    }
  }
  return len == INT_MAX ? 0 : len;
}

vector<int> twoSum(vector<int>& nums, int target) {
  // 使用哈希表把每个元素的下表记录下来
  unordered_map<int, int> hashtable;
  for (auto i = 0; i < nums.size(); i++) {
    hashtable.insert(make_pair(nums[i], i));
  }
  for (auto i = 0; i < nums.size(); i++) {
    auto it = hashtable.find(target - nums[i]);
    if (it != hashtable.end()) return {i, it->second};
  }
  return {};
}

}  // namespace leetcode