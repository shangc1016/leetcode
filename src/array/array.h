#include <limits.h>

#include <algorithm>
#include <queue>
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

}  // namespace leetcode