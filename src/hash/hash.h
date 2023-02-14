#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

namespace leetcode {

bool isAnagram(string s, string t);

// 数组的交集 https://leetcode.cn/problems/intersection-of-two-arrays/
vector<int> intersection(vector<int>& nums1, vector<int>& nums2);

// 两个数组的交集
vector<int> intersect(vector<int>& nums1, vector<int>& nums2);

// 快乐数 https://leetcode.cn/problems/happy-number/
bool isHappy(int n);
// 两数之和 https://leetcode.cn/problems/two-sum/
vector<int> twoSum(vector<int>& nums, int target);

// 四数之和 https://leetcode.cn/problems/4sum-ii/
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                 vector<int>& nums4);

// 字符串哈希表 https://leetcode.cn/problems/ransom-note/
bool canConstruct(string ransomNote, string magazine);

// 三数之和 https://leetcode.cn/problems/3sum/
vector<vector<int>> threeSum(vector<int>& nums);

// TODO: 四数之和 https://leetcode.cn/problems/4sum/
vector<vector<int>> fourSum(vector<int>& nums, int target);
}  // namespace leetcode