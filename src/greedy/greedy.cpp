#include "greedy.h"

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>

namespace leetcode {

int findContentChildren(vector<int>& g, vector<int>& s) {
  sort(g.begin(), g.end());
  sort(s.begin(), s.end());
  int count = 0;
  int i = 0, j = 0;
  while (i < g.size() && j < s.size()) {
    if (s[j] >= g[i]) {
      count++;
      i++;
      j++;
    } else {
      j++;
    }
  }
  return count;
}

int wiggleMaxLength(vector<int>& nums) {
  if (nums.size() <= 1) return nums.size();
  int curDiff = 0;  // 当前一对差值
  int preDiff = 0;  // 前一对差值
  int result = 1;  // 记录峰值个数，序列默认序列最右边有一个峰值
  for (int i = 0; i < nums.size() - 1; i++) {
    curDiff = nums[i + 1] - nums[i];
    // 出现峰值
    if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
      result++;
    }
    preDiff = curDiff;
  }
  return result;
}

int maxSubArray(vector<int>& nums) {
  //   动态规划
  vector<int> dp(nums.size(), 0);
  dp[0] = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    dp[i] = max(dp[i - 1] + nums[i], nums[i]);
  }
  int max = dp[0];
  for (int i = 1; i < dp.size(); i++) {
    if (max < dp[i]) max = dp[i];
  }
  return max;
}

int maxProfit(vector<int>& prices) {
  vector<int> profile(prices.size() - 1, 0);
  int all_profile = 0;
  for (int i = 0; i < profile.size(); i++) {
    profile[i] = prices[i + 1] - prices[i];
    if (profile[i] > 0) all_profile += profile[i];
  }
  return all_profile;
}

bool canJump(vector<int>& nums) {
  if (nums.size() == 1) return true;
  int max_range = 0;
  for (int i = 0; i <= max_range; i++) {
    max_range = max(max_range, i + nums[i]);
    if (max_range >= nums.size() - 1) return true;
  }
  return false;
}

static bool compare(int a, int b) { return abs(a) > abs(b); }
int largestSumAfterKNegations(vector<int>& nums, int k) {
  sort(nums.begin(), nums.end(), compare);
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] < 0 && k > 0) {
      nums[i] = abs(nums[i]);
      k--;
    }
  }
  while (k-- > 0) nums[nums.size() - 1] = -nums[nums.size() - 1];
  int count = 0;
  for (auto item : nums) count += item;
  return count;
}
}  // namespace leetcode