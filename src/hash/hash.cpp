#include "hash.h"

#include <algorithm>
#include <cstdio>
#include <map>
#include <unordered_map>
#include <utility>
#include <vector>

namespace leetcode {

bool isAnagram(string s, string t) {
  unordered_map<char, int> mapA;
  unordered_map<char, int> mapB;
  for (auto ch : s) mapA[ch]++;
  for (auto ch : t) mapB[ch]++;
  if (mapA.size() != mapB.size()) return false;
  for (auto item : mapA) {
    if (item.second != mapB[item.first]) return false;
  }
  return true;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  vector<int> array;
  unordered_map<int, int> map1;
  unordered_map<int, int> map2;
  for (auto item : nums1) map1[item] = 1;
  for (auto item : nums2) map2[item] = 1;
  for (auto item : map1) {
    if (map2.find(item.first) != map2.end()) array.push_back(item.first);
  }
  return array;
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
  vector<int> array;
  unordered_map<int, int> map1;
  unordered_map<int, int> map2;
  for (auto item : nums1) map1[item]++;
  for (auto item : nums2) map2[item]++;
  for (auto item : map1) {
    if (map2.find(item.first) != map2.end()) {
      int count =
          item.second > map2[item.first] ? map2[item.first] : item.second;
      while (count--) array.push_back(item.first);
    }
  }
  return array;
}

bool isHappy(int n) {
  //   判断数字能不能回到1
  unordered_map<int, int> map;
  while (n != 1) {
    int sum = 0;
    while (n) {
      sum += (n % 10) * (n % 10);
      n /= 10;
    }
    if (map.find(sum) != map.end()) return false;
    map[sum] = 1;
    n = sum;
  }
  return true;
}

vector<int> twoSum(vector<int>& nums, int target) {
  //   先把数组中每个元素去重，用map
  unordered_map<int, int> map;
  for (auto i = 0; i < nums.size(); i++) map[nums[i]] = i;
  //   step2: 找到是target - nums[i]的元素
  for (auto i = 0; i < nums.size(); i++) {
    if (map.find(target - nums[i]) != map.end() && i != map[target - nums[i]])
      return {i, map[target - nums[i]]};
  }
  return {};
}

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                 vector<int>& nums4) {
  int count = 0;
  unordered_map<int, int> umap;
  for (auto i : nums1) {
    for (auto j : nums2) umap[i + j]++;
  }

  for (auto i : nums3) {
    for (auto j : nums4) {
      if (umap.find(-i - j) != umap.end()) {
        count += umap[-i - j];
      }
    }
  }
  return count;
}

bool canConstruct(string ransomNote, string magazine) {
  unordered_map<int, int> umap;
  for (auto ch : magazine) umap[ch]++;
  for (auto ch : ransomNote) {
    if (umap.find(ch) == umap.end()) return false;
    if (umap[ch] <= 0) return false;
    umap[ch]--;
  }
  return true;
}

// 这个题目看似是和两个数组的两数之和，四个数组的四数之和类似，
// 但是是在同一个数组中的操作，而且规定i!=j!=k，考虑双指针
vector<vector<int>> threeSum(vector<int>& nums) {
  vector<vector<int>> vec;

  std::sort(nums.begin(), nums.end());

  for (auto i = 0; i < nums.size(); i++) {
    if (nums[i] > 0 || nums[nums.size() - 1] < 0) return vec;
    if (i > 0 && nums[i] == nums[i - 1]) continue;
    int left = i + 1;
    int right = nums.size() - 1;
    while (left < right) {
      if (nums[i] + nums[left] + nums[right] > 0)
        right--;
      else if (nums[i] + nums[left] + nums[right] < 0)
        left++;
      else {
        // 两边收缩
        vec.push_back({nums[i], nums[left], nums[right]});
        while (left < right && nums[left] == nums[left + 1]) left++;
        while (left < right && nums[right] == nums[right - 1]) right--;
        right--;
        left++;
      }
    }
  }
  return vec;
}


}  // namespace leetcode