#ifndef __SLIDEWINDOW_H_
#define __SLIDEWINDOW_H_

#include <deque>
#include <functional>
#include <queue>
#include <string>
#include <vector>

using namespace std;
namespace leetcode {

int lengthOfLongestSubstring(string s);

vector<string> generateParenthesis(int n);

// 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
// 输出 : [ 3, 3, 5, 5, 6, 7 ]

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  deque<int> queue;
  vector<int> result(nums.size() + k - 1, 0);
  for (int i = 0; i < k; i++) {
    while (!queue.empty() && queue.back() < nums[i]) queue.pop_back();
    queue.push_back(nums[i]);
  }
  for (int i = 0; i < nums.size() - k + 1; i++) {
    if (i != 0) {
      while (!queue.empty() && queue.back() < nums[i + k]) queue.pop_back();
      queue.push_back(nums[i + k]);
    }
    if (i != 0 && nums[i - 1] == queue.front()) queue.pop_front();
    result[i] = queue.front();
  }
  return result;
}
}  // namespace leetcode

#endif