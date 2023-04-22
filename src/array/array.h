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

void rotate(vector<vector<int>>& matrix);

void moveZeroes(vector<int>& nums);

int trap(vector<int>& height);

}  // namespace leetcode