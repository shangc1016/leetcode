#include <limits.h>

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

}  // namespace leetcode