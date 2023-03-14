#ifndef _BACK_TRACING_H_
#define _BACK_TRACING_H_

#include <algorithm>
#include <cstdlib>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

namespace leetocde {

// class Solution {
//  private:
//   vector<int> path;
//   vector<vector<int>> vec;

//   void backtracing(int n, int k, int startIndex) {
//     if (path.size() >= k) {
//       vec.push_back(path);
//       return;
//     }
//     for (int i = startIndex; i <= n; i++) {
//       path.push_back(i);
//       backtracing(n, k, i + 1);
//       path.pop_back();
//     }
//   }
//  public:
//   vector<vector<int>> combine(int n, int k) {
//     backtracing(n, k, 1);
//     return vec;
//   }
// };

// class Solution {
//  private:
//   vector<int> path;
//   vector<vector<int>> vec;
//   void backtracing(int n, int k, int startIndex) {
//     if (path.size() == k) {
//       int sum = 0;
//       for (auto item : path) sum += item;
//       if (sum == n) {
//         vec.push_back(path);
//         return;
//       }
//     }
//     for (int i = startIndex; i <= 9; i++) {
//       path.push_back(i);
//       backtracing(n, k, i + 1);
//       path.pop_back();
//     }
//   }

//  public:
//   vector<vector<int>> combinationSum3(int k, int n) {
//     backtracing(n, k, 1);
//     return vec;
//   }
// };

// class Solution {
//  private:
//   const string lettermap[20] = {
//       "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
//   };
//   vector<string> result;
//   string s;

//   void backtracing(const string &digits, int index) {
//     if (index == digits.size()) {
//       result.push_back(s);
//       return;
//     }
//     int digit = digits[index] - '0';
//     string letter = lettermap[digit];
//     for (int i = 0; i < letter.size(); i++) {
//       s.push_back(letter[i]);
//       backtracing(digits, index + 1);
//       s.pop_back();
//     }
//   }

//  public:
//   vector<string> letterCombinations(string digits) {
//     if (digits.size() == 0) {
//       return result;
//     }
//     backtracing(digits, 0);
//     return result;
//   }
// };

// class Solution {
//  private:
//   vector<int> path;
//   vector<vector<int>> vec;
//   void backtracing(vector<int> &candidates, int target, int sum, int
//   startIndex) {
//     if (sum == target) {
//       vec.push_back(path);
//     } else if (sum > target) {
//       return;
//     }
//     for (int i = startIndex; i < candidates.size(); i++) {
//       sum += candidates[i];
//       path.push_back(candidates[i]);
//       backtracing(candidates, target, sum, i);
//       sum -= candidates[i];
//       path.pop_back();
//     }
//   }
//  public:
//   vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//     backtracing(candidates, target, 0, 0);

//     return vec;
//   }
// };

// 这个题首先要对数组排序，排序之后相同的元素出现在相邻的位置，然后再用used数组判断是否已经访问过了
// class Solution {
//  private:
//   vector<int> path;
//   vector<vector<int>> vec;

//   void backtracing(vector<int>& candidates, int target, int startIndex,
//                    int partSum) {
//     if (partSum == target) {
//       vec.push_back(path);
//       return;
//     }

//     for (int i = startIndex; i < candidates.size(); i++) {
//       if (i > 0 && candidates[i - 1] == candidates[i]) continue;
//       path.push_back(candidates[i]);
//       partSum += candidates[i];
//       backtracing(candidates, target, i + 1, partSum);
//       partSum -= candidates[i];
//       path.pop_back();
//     }
//   }

//  public:
//   vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//     sort(candidates.begin(), candidates.end());
//     backtracing(candidates, target, 0, 0);
//     return vec;
//   }
// };

// class Solution {
//  private:
//   vector<string> path;
//   vector<vector<string>> vec;
//   bool isPalindrome(string &str, int left, int right) {
//     while (left < right) {
//       if (str[left] != str[right]) return false;
//       left++;
//       right--;
//     }
//     return true;
//   }

//   void backtracing(string &s, int startIndex) {
//     if (startIndex >= s.size()) {
//       vec.push_back(path);
//       return;
//     }
//     for (int i = startIndex; i < s.size(); i++) {
//       if (isPalindrome(s, startIndex, i)) {
//         string substr = s.substr(startIndex, i - startIndex + 1);
//         path.push_back(substr);
//       } else {
//         continue;
//       }
//       backtracing(s, i + 1);
//       path.pop_back();
//     }
//   }

//  public:
//   vector<vector<string>> partition(string s) {
//     backtracing(s, 0);
//     return vec;
//   }
// };

// class Solution {
//  private:
// //   string path;
//   vector<string> vec;
//   bool isValid(string &s, int start, int end) {
//     if (start > end) return false;
//     if (s[start] == '0' && start != end) return false;
//     int num = 0;
//     for (int i = start; i <= end; i++) {
//       if (s[i] > '9' || s[i] < '0') return false;
//       num = num * 10 + (s[i] - '0');
//       if (num > 255) return false;
//     }
//     return true;
//   }

//   void backtracing(string &s, int startIndex, int pointNum) {

//     if (pointNum == 3) {
//       if (isValid(s, startIndex, s.size() - 1)) {
//         vec.push_back(s);
//       }
//       return;
//     }

//     for (int i = startIndex; i < s.size(); i++) {
//       if (isValid(s, startIndex, i)) {
//         s.insert(s.begin() +i + 1, '.');
//         pointNum++;
//         backtracing(s, i + 2, pointNum);
//         pointNum--;
//         s.erase(s.begin() + 1 + i);
//       } else
//         break;
//     }
//   }

//  public:
//   vector<string> restoreIpAddresses(string s) {
//     if(s.size() < 4 || s.size() > 12) return {};
//     backtracing(s, 0, 0);
//     return vec;
//   }
// };

// class Solution {
//  private:
//   vector<int> path;
//   vector<vector<int>> vec;

//   void backtracing(vector<int>& nums, int startIndex) {
//     if (startIndex > nums.size()) {
//       return;
//     }

//     for (int i = startIndex; i < nums.size(); i++) {
//       if(i > startIndex && nums[i - 1] == nums[i]) continue;
//       path.push_back(nums[i]);
//       vec.push_back(path);
//       backtracing(nums, i + 1);
//       path.pop_back();
//     }
//   }

//  public:
//   vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
//     backtracing(nums, 0);
//     vec.push_back({});
//     return vec;
//   }
// };

// class Solution {

//  private:
//   vector<int> path;
//   vector<vector<int>> vec;
//   void backtracing(vector<int> &nums, int startIndex) {
//     if(path.size() >= 2) vec.push_back(path);

//     // unordered_set<int> uset;
//     for (int i = startIndex; i < nums.size(); i++) {
//       // if(!path.empty() &&  nums[i] < path.back() || uset.find(nums[i]) !=
//       // uset.end()) continue;
//       if( !path.empty() && nums[i] < path.back() || i > startIndex && nums[i]
//       == nums[i-1]) continue; path.push_back(nums[i]); backtracing(nums, i +
//       1); path.pop_back();
//     }
//   }
//  public:
//   vector<vector<int>> findSubsequences(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
//     backtracing(nums, 0);
//     return vec;
//   }
// };

// class Solution {
//  private:
//   vector<int> path;
//   vector<vector<int>> vec;
//   void backtracing(vector<int>& nums, int startIndex, vector<bool> used) {
//     if (path.size() == nums.size()) {
//       vec.push_back(path);
//       return;
//     }

//     for (int i = 0; i < nums.size(); i++) {
//       if(used[i]) continue;
//       used[i] = true;
//       path.push_back(nums[i]);
//       backtracing(nums, i + 1, used);
//       path.pop_back();
//       used[i] = false;
//     }
//   }

//  public:
//   vector<vector<int>> permute(vector<int>& nums) {
//     vector<bool> used(nums.size(), false);
//     backtracing(nums, 0, used);
//     return vec;
//   }
// };

// class Solution {
//  private:
//   vector<int> path;
//   vector<vector<int>> vec;
//   void backtracing(vector<int>& nums, int startIndex, vector<bool> &used) {
//     if (path.size() == nums.size()) {
//       vec.push_back(path);
//       return;
//     }

//     for (int i = 0; i < nums.size(); i++) {
//       if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false) continue;
//       if (used[i]) continue;
//       used[i] = true;
//       path.push_back(nums[i]);
//       backtracing(nums, i + 1, used);
//       path.pop_back();
//       used[i] = false;
//     }
//   }

//  public:
//   vector<vector<int>> permuteUnique(vector<int>& nums) {
//     vector<bool> used(nums.size(), false);
//     sort(nums.begin(), nums.end());
//     backtracing(nums, 0, used);
//     return vec;
//   }
// };

// class Solution {
//  private:
//   vector<int> path;
//   vector<vector<int>> vec;
//   void backtracing(vector<int>& nums, int startIndex, vector<bool>& used) {
//     if (path.size() == nums.size()) {
//       vec.push_back(path);
//       return;
//     }

//     for (int i = 0; i < nums.size(); i++) {
//       if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
//       if (used[i] == false) {
//         used[i] = true;
//         path.push_back(nums[i]);
//         backtracing(nums, i + 1, used);
//         path.pop_back();
//         used[i] = false;
//       }
//     }
//   }

//  public:
//   vector<vector<int>> permuteUnique(vector<int>& nums) {
//     vector<bool> used(nums.size(), false);
//     sort(nums.begin(), nums.end());
//     backtracing(nums, 0, used);
//     return vec;
//   }
// };

// class Solution {
//  private:
//   vector<vector<string>> result;

//   // n为棋盘大小，n*n
//   // row是棋盘第几行
//   void backtracing(int n, int row, vector<string> &chessboard) {
//     if (n == row) {
//       result.push_back(chessboard);
//       return;
//     }

//     // for循环遍历
//     for (int col = 0; col < n; col++) {
//       if (isValid(row, col, chessboard, n)) {
//         chessboard[row][col] = 'Q';
//         backtracing(n, row + 1, chessboard);
//         chessboard[row][col] = '.';
//       }
//     }
//   }

//   bool isValid(int row, int col, vector<string> &chessboard, int n) {
//     // 检查同一列
//     for (int i = 0; i < row; i++) {
//       if (chessboard[i][col] == 'Q') return false;
//     }
//     // 检查45度是否有冲突
//     for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
//       if (chessboard[i][j] == 'Q') return false;
//     }

//     // 检查135度是否有冲突
//     for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
//       if (chessboard[i][j] == 'Q') return false;
//     }

//     return true;
//   }

//  public:
//   vector<vector<string>> solveNQueens(int n) {
//     result.clear();
//     std::vector<string> chessboard(n, string(n, '.'));
//     backtracing(n, 0, chessboard);
//     return result;
//   }
// };

class Solution {
 public:
  vector<string> brackets;
  string str;
  void dfs(const string &str, int left, int right) {
    if (left < 0 || left > right) return;
    if (left == 0 && right == 0) {
      brackets.push_back(str);
    }
    dfs(str + '(', left - 1, right);
    dfs(str + ')', left, right - 1);
  }
  vector<string> generateParenthesis(int n) {
    dfs(str, n, n);
    return brackets;
  }
};

}  // namespace leetocde

#endif