#include <limits.h>

#include <algorithm>
#include <array>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

namespace leetcode {
void array();

int minSubArrayLen(int, vector<int>&);

vector<vector<int>> generateMatrix(int n);

vector<int> twoSum(vector<int>& nums, int target);

// 数组中除自身外其他元素乘积
vector<int> constructArr(vector<int>& a);

// 数组中除自身外其他元素乘积
vector<int> productExceptSelf(vector<int>& nums);

// 二维数组查找
bool searchMatrix(vector<vector<int>>& matrix, int target);

int findKthLargest(vector<int>& nums, int k);

vector<int> partSum(vector<int>& nums, int startIndex) {
  vector<int> vec;
  int sum = nums[startIndex];
  vec.push_back(sum);
  for (int i = startIndex + 1; i < nums.size(); i++) {
    sum += nums[i];
    vec.push_back(sum);
  }
  return vec;
}

int rangeSum(vector<int>& nums, int n, int left, int right) {
  vector<int> result;
  for (int i = 0; i < nums.size(); i++) {
    auto vec = partSum(nums, i);
    result.insert(result.end(), vec.begin(), vec.end());
  }
  std::sort(result.begin(), result.end());

  int sum = 0;
  for (int i = left; i <= right; i++) {
    sum += result[i];
  }
  return sum;
}

int pivotIndex(vector<int>& nums) {
  if (nums.size() == 1) return 0;
  int sum = 0;
  for (int item : nums) sum += item;
  int leftSum = nums[0];
  int rightSum;
  for (int i = 1; i < nums.size(); i++) {
    rightSum = sum - leftSum - nums[i];
    if (leftSum == rightSum) return i;
    leftSum += nums[i];
  }
  return -1;
}

class Solution_215 {
 private:
  int partition(vector<int>& nums, int low, int high) {
    int i = low;
    int j = high + 1;
    int value = nums[low];
    while (true) {
      while (nums[++i] > value)
        if (i == high) break;
      while (value > nums[--j])
        if (j == low) break;
      if (i >= j) break;
      swap(nums[i], nums[j]);
    }
    swap(nums[j], nums[low]);
    return j;
  }

  int helper(vector<int>& nums, int low, int high, int k) {
    if (low >= high) return nums[low];
    while (true) {
      int pivot = partition(nums, low, high);
      if (pivot == k)
        return nums[pivot];
      else if (pivot > k) {
        return helper(nums, low, pivot - 1, k);
      } else {
        return helper(nums, pivot + 1, high, k);
      }
    }
  }

 public:
  int findKthLargest(vector<int>& nums, int k) {
    if (k > nums.size()) return 0;
    return helper(nums, 0, nums.size() - 1, k - 1);
  }
};

class Solution {
 private:
  string result;

  void helper(string s) {
    if (s.empty()) return;
    queue<string> queue;
    queue.push(s);
    while (!queue.empty()) {
      string str = queue.front();
      queue.pop();
      string reverse(str.rbegin(), str.rend());
      if (reverse.compare(str) == 0) {
        result = reverse;
        return;
      }
      if (!str.empty()) {
        queue.push(str.substr(1));
        queue.push(str.substr(0, str.size() - 1));
      }
    }
  }

 public:
  string longestPalindrome(string s) {
    helper(s);
    return result;
  }
};

}  // namespace leetcode