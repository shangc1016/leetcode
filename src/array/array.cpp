#include "array.h"

#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

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

vector<int> constructArr(vector<int>& a) {
  vector<int> left2right(a.size(), 1);
  vector<int> right2left(a.size(), 1);
  for (int i = 1; i < a.size(); i++) {
    left2right[i] = left2right[i - 1] * a[i - 1];
  }
  for (int i = a.size() - 1; i >= 0; i--) {
    right2left[i] = right2left[i + 1] * a[i + 1];
  }
  for (int i = 0; i < a.size(); i++) {
    left2right[i] *= right2left[i];
  }
  return left2right;
}

vector<int> productExceptSelf(vector<int>& nums) {
  vector<int> left2right(nums.size(), 1);
  vector<int> right2left(nums.size(), 1);

  for (int i = 1; i < nums.size(); i++) {
    left2right[i] = left2right[i - 1] * nums[i - 1];
  }
  for (int i = nums.size() - 2; i >= 0; i--) {
    right2left[i] = right2left[i + 1] * nums[i + 1];
  }
  for (int i = 0; i < nums.size(); i++) {
    left2right[i] *= right2left[i];
  }
  return left2right;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
  if (target < matrix[0][0]) return false;
  int h = matrix.size();
  int w = matrix[0].size();
  if (target > matrix[h - 1][w - 1]) return false;

  int row = h - 1;
  int col = 0;
  while (row >= 0 && col < w) {
    if (target > matrix[row][col]) {
      col++;
    } else if (target < matrix[row][col]) {
      row--;
    } else {
      return true;
    }
  }
  return false;
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());
  int cur1 = 0;
  int cur2 = 0;
  while (cur1 < nums1.size() && nums1[cur1] < nums2[cur2]) cur1++;
  while (cur2 < nums2.size() && nums2[cur2] < nums1[cur1]) cur2++;

  vector<int> ans;
  while (cur1 < nums1.size() && cur2 < nums2.size()) {
    if (nums1[cur1] == nums2[cur2]) {
      ans.push_back(nums1[cur1]);
      cur1++;
      cur2++;
    } else if (nums1[cur1] > nums2[cur2]) {
      cur2++;
    } else {
      cur1++;
    }
  }
  return ans;
}

// 只能交易一次
// dp[i][0]表示i天持有股票的最大金额
// dp[i][1]表示i天不持有股票的最金额

// dp[i][0]有两种情况：
// 1、前一天没有股票，今天当天购买dp[i][0] = -prices[i] //
// 因为只能交易一次，如果前一天没有持有股票，金额不用参考前一天的不持有状态了
// 2、前一天已经有股票了， dp[i][0] = dp[i-1][0]

// dp[i][1]有两种情况
// 1、前一天持有股票，今天卖出dp[i-1][0] + prices[i]
// 2、前一天不持有股票，dp[i-1][1]
int maxProfit(vector<int>& prices) {
  vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
  dp[0][0] = -prices[0];
  for (int i = 1; i < prices.size(); i++) {
    dp[i][0] = max(dp[i - 1][0], -prices[i]);
    dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
  }
  return dp[prices.size() - 1][1];
}

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
  int row = mat.size();
  int col = mat[0].size();
  if (row * col != r * c) return mat;

  vector<vector<int>> ans(r, vector<int>(c, 0));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int sum = i * c + j;
      int nr = sum / col;
      int nc = sum % col;
      ans[i][j] = mat[nr][nc];
    }
  }
  return ans;
}

void setZeroes(vector<vector<int>>& matrix) {
  set<int> uset1, uset2;
  int r = matrix.size();
  int c = matrix[0].size();
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (matrix[i][j] == 0) {
        uset1.insert(i);
        uset2.insert(j);
      }
    }
  }

  for (int i = 0; i < r; i++) {
    if (uset1.find(i) != uset1.end()) {
      matrix[i].clear();
      for(int i=0;i<c;i++) matrix[i].push_back(0);
    }
  }
  for (int i = 0; i < r; i++) {
    if (uset1.find(i) != uset1.end()) continue;
    for (int j = 0; j < c; j++) {
      if (uset2.find(j) != uset2.end()) {
        matrix[i][j] = 0;
      }
    }
  }
}

}  // namespace leetcode