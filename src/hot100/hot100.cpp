#include "hot100.h"

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <list>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace hot100 {

// 两数之和
vector<int> twoSum(vector<int>& nums, int target) {
  vector<int> result;
  for (int i = 0; i < nums.size(); i++) {
    for (int j = i; j < nums.size(); j++) {
      if (nums[i] + nums[j] == target) {
        result.push_back(i);
        result.push_back(j);
        break;
      }
    }
  }
  return result;
}

// 字母异位词

string helper(const string& str) {
  auto tmp = str;
  sort(tmp.begin(), tmp.end());
  return tmp;
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {
  map<string, vector<string>> map;
  vector<vector<string>> result;
  for (auto& str : strs) {
    map[helper(str)].push_back(str);
  }
  for (auto item : map) {
    result.push_back(item.second);
  }
  return result;
}

// 最长连续序列
// 对每一个元素x，查找是否存在x+1，x+2...
int longestConsecutive(vector<int>& nums) {
  unordered_set<int> uset;
  for (auto item : nums) uset.insert(item);
  int longestSeq = 0;
  for (auto item : uset) {
    // 只有再找不到x-1的时候，从x开始下面的查找才有意义。要不然从前一个的连续序列肯定更长
    if (uset.find(item - 1) == uset.end()) {
      int current = 0;
      int value = item;
      while (uset.find(value++) != uset.end()) current++;
      longestSeq = max(longestSeq, current);
    }
  }
  return longestSeq;
}

// 移动零
void moveZeroes(vector<int>& nums) {
  int pos = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] != 0) {
      nums[pos++] = nums[i];
    }
  }
  for (int i = pos; i < nums.size(); i++) {
    nums[i] = 0;
  }
}

// 盛水量
// (right - left) * min(left, right)
// 双指针怎么缩减，
// 大的向内，只会减少
// 小的向内，可能增大
int maxArea(vector<int>& height) {
  int left = 0;
  int right = height.size() - 1;
  int result = 0;
  while (left < right) {
    int area = (right - left) * min(height[left], height[right]);
    result = max(area, result);
    if (height[left] > height[right])
      right--;
    else
      left++;
  }
  return result;
}

// 三数之和
vector<vector<int>> threeSum(vector<int>& nums) {
  // 先排序
  // 把数组元素全部放在set中
  vector<vector<int>> result;
  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size(); i++) {
    // 这一层循环固定一个值nums[i]，然后再i之后，区左右两端L、R，使用双指针方法
    // 如果nums[i]大于0，说明后面的都大于0，而且已经是有序的，直接break
    if (nums[i] > 0) break;
    // 去重
    if (i != 0 && nums[i] == nums[i - 1]) continue;
    int left = i + 1, right = nums.size() - 1;
    while (left < right) {
      int sum = nums[i] + nums[left] + nums[right];
      if (sum == 0) {
        result.push_back({nums[i], nums[left], nums[right]});
        while (left < right && nums[left] == nums[left + 1]) left++;
        while (left < right && nums[right] == nums[right - 1]) right--;
      }
      if (sum > 0) right--;
      if (sum < 0) left++;
    }
  }
  return result;
}

// 接雨水
int trap(vector<int>& height) {
  //
  // 分别计算数组当前下标i位置左侧，右侧最大值
  // 只有当前下标的值小于min(left, right)的时候，才能存储水

  vector<int> leftHeight;
  vector<int> rightHeight;

  for (int i = 0; i < height.size(); i++) {
    if (!leftHeight.empty()) {
      leftHeight.push_back(max(leftHeight.back(), height[i]));
    } else {
      leftHeight.push_back(height[i]);
    }
  }
  for (int i = height.size() - 1; i >= 0; i--) {
    if (!rightHeight.empty()) {
      rightHeight.push_back(max(rightHeight.back(), height[i]));
    } else {
      rightHeight.push_back(height[i]);
    }
  }

  int count = 0;
  for (int i = 0; i < height.size(); i++) {
    if (height[i] < min(leftHeight[i], rightHeight[i])) {
      count += min(leftHeight[i], rightHeight[i]) - height[i];
    }
  }
  return count;
}

// 最长无重复子串
int lengthOfLongestSubstring(string s) {
  // 滑动窗口，窗口中的元素用set集合表示
  unordered_set<char> window;
  int length = 0;
  int windowStartIndex = 0;
  for (int cur = 0; cur < s.size(); cur++) {
    while (window.find(s[cur]) != window.end()) {
      window.erase(s[windowStartIndex]);
      windowStartIndex++;
    }
    length = max(length, cur - windowStartIndex + 1);
    window.insert(s[cur]);
  }
  return length;
}

// 找到字符串中所有的异位词
// 滑动窗口
vector<int> findAnagrams(string s, string p) {
  //
  // 用数组当做map，记录子串包含的字符，如果两个子串包含的字符相同，那就是异位置词
  if (p.size() > s.size()) return {};
  vector<int> pchar(26);
  vector<int> schar(26);
  vector<int> result;
  for (int i = 0; i < p.size(); i++) {
    pchar[p[i] - 'a']++;
    schar[s[i] - 'a']++;
  }

  if (schar == pchar) {
    result.push_back(0);
  }

  for (int i = 1; i < s.size() - p.size() + 1; i++) {
    schar[s[i - 1] - 'a']--;
    schar[s[i + p.size()] - 'a']++;
    if (schar == pchar) {
      result.push_back(i);
    }
  }
  return result;
}

int subarraySum(vector<int>& nums, int k) {
  unordered_map<int, int> mp;
  mp[0] = 1;
  int count = 0, pre = 0;
  for (auto& x : nums) {
    pre += x;
    if (mp.find(pre - k) != mp.end()) {
      count += mp[pre - k];
    }
    mp[pre]++;
  }
  return count;
}

// 滑动窗口最大值
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  //
  // 单调队列
  list<int> window;
  for (int i = 0; i < k; i++) {
    while (!window.empty() && window.back() < nums[i]) window.pop_back();
    window.push_back(nums[i]);
  }
  vector<int> result;
  result.push_back(window.front());
  for (int i = k; i < nums.size(); i++) {
    if (window.front() == nums[i - k]) window.pop_front();
    while (!window.empty() && window.back() < nums[i]) window.pop_back();
    window.push_back(nums[i]);
    result.push_back(window.front());
  }
  return result;
}

// // 最小覆盖子集
// string minWindow(string s, string t) {
//   // fast先往前走，之道fast、slow之间包括t的所有元素
//   //
//   然后比较更新长度，然后slow往前走一步，此时fast、slow之间不满足了，fast继续向前走，直到再次符合
//   // 或者fast到s的末尾。
//   //
//   int fast{}, slow{};
//   unordered_set<int> uset;
//   unordered_set<int> sset;
//   for(char ch : t) uset.insert(ch - 'a');
//   string result;
//   while (fast < s.size()) {
//     if (sset == uset) {
//       result =
//     }
//   }
// }

// 最大子序列和
int maxSubArray(vector<int>& nums) {
  //
  //
  vector<int> dp(nums.size(), 0);
  dp[0] = nums[0];
  int result = dp[0];
  for (int i = 1; i < nums.size(); i++) {
    dp[i] = dp[i - 1] > 0 ? nums[i] + dp[i - 1] : nums[i];
    result = max(result, dp[i]);
  }
  return result;
}

//
vector<vector<int>> merge(vector<vector<int>>& intervals) {
  vector<vector<int>> result;
  sort(intervals.begin(), intervals.end());
  for (int i = 0; i < intervals.size();) {
    int start = intervals[i][0];
    int end = intervals[i][1];
    int j = i + 1;
    while (j < intervals.size() && end >= intervals[j][0]) {
      end = max(end, intervals[j][1]);
      j++;
    }
    result.push_back({start, end});
    i = j;
  }
  return result;
}

void reverse(vector<int>& nums, int left, int right) {
  while (left < right) {
    swap(nums[left], nums[right]);
    left++;
    right--;
  }
}
// 数组向右旋转k个位置
void rotate(vector<int>& nums, int k) {
  k %= nums.size();

  reverse(nums, 0, nums.size() - 1);
  reverse(nums, 0, k - 1);
  reverse(nums, k, nums.size() - 1);
}

// 除自身以外数组的乘积
vector<int> productExceptSelf(vector<int>& nums) {
  int sz = nums.size();
  vector<int> left(sz, 0);
  vector<int> right(sz, 0);
  left[0] = 1;
  right[sz - 1] = 1;
  for (int i = 1; i < sz; i++) {
    left[i] = left[i - 1] * nums[i - 1];
  }
  for (int i = sz - 2; i >= 0; i--) {
    right[i] = right[i + 1] * nums[i + 1];
  }
  for (int i = 0; i < sz; i++) {
    left[i] *= right[i];
  }
  return left;
}

// 缺失的第一个正数
int firstMissingPositive(vector<int>& nums) {
  // 先遍历一遍数组，把负数全部变成N+1
  int sz = nums.size();
  for (int& item : nums) {
    if (item <= 0) item = sz + 1;
  }
  for (int i = 0; i < sz; i++) {
    int num = abs(nums[i]);
    if (num <= sz) {
      nums[num - 1] = -abs(nums[num - 1]);
    }
  }
  for (int i = 0; i < sz; i++) {
    if (nums[i] > 0) {
      return i + 1;
    }
  }
  return sz + 1;
}

class Solution_73 {
 private:
  void setRowZero(vector<vector<int>>& matrix, int row) {
    std::fill(matrix[row].begin(), matrix[row].end(), 0);
  }
  void setColZero(vector<vector<int>>& matrix, int col) {
    for (int i = 0; i < matrix.size(); i++) {
      matrix[i][col] = 0;
    }
  }

 public:
  void setZeroes(vector<vector<int>>& matrix) {
    unordered_set<int> row_set;
    unordered_set<int> col_set;
    for (int i = 0; i < matrix.size(); i++) {
      if (row_set.find(i) != row_set.end()) continue;
      for (int j = 0; j < matrix[0].size(); j++) {
        if (col_set.find(j) != col_set.end()) continue;
        if (matrix[i][j] == 0) {
          row_set.insert(i);
          col_set.insert(j);
          break;
        }
      }
    }
    for (auto item : row_set) {
      setRowZero(matrix, item);
    }
    for (auto item : col_set) {
      setColZero(matrix, item);
    }
  }
};

// 顺时针旋转矩阵90°
void rotate(vector<vector<int>>& matrix) {
  // 先上下翻转
  // 然后沿着主对称线旋转
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < i; j++) {
      swap(matrix[i][j], matrix[j][j]);
    }
  }
  for (int i = 0; i < matrix.size() / 2; i++) {
    swap(matrix[i], matrix[matrix.size() - i]);
  }
}

// 搜索二维矩阵
bool searchMatrix(vector<vector<int>>& matrix, int target) {
  //
  int r = matrix.size();
  int c = matrix[0].size();
  if (target < matrix[0][0] || target > matrix[r - 1][c - 1]) return false;
  int x = r - 1;
  int y = 0;
  while (x >= 0 && y < c) {
    if (matrix[x][y] > target) {
      x--;
    } else if (matrix[x][y] < target) {
      y++;
    } else {
      return true;
    }
  }
  return false;
}

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
  if (headA == nullptr || headB == nullptr) return nullptr;
  ListNode* ptrA = headA;
  ListNode* ptrB = headB;
  while (ptrA != ptrB) {
    ptrA = ptrA ? ptrA->next : headB;
    ptrB = ptrB ? ptrB->next : headA;
  }
  return ptrA;
}

// 反转链表
ListNode* reverseList(ListNode* head) {
  if (head == nullptr) return nullptr;
  ListNode* reverse = nullptr;
  ListNode* ptr;
  ListNode* cur = head;
  while (cur) {
    ptr = cur;
    cur = cur->next;
    ptr->next = reverse;
    reverse = ptr;
  }
  return reverse;
}

}  // namespace hot100