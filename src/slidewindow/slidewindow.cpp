#include "slidewindow.h"

#include <algorithm>
#include <cstddef>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace leetcode {

int lengthOfLongestSubstring(string s) {
  if (s.size() <= 1) return s.size();
  unordered_set<char> uset;
  int left = 0;
  int right = 0;
  int max_sz = 0;
  for (; right < s.size(); right++) {
    char ch = s[right];
    while (uset.find(ch) != uset.end()) {
      uset.erase(s[left++]);
    }
    uset.insert(ch);
    max_sz = max(max_sz, right - left + 1);
  }
  return max_sz;
}

void helper(vector<string> &vec, int &left_brk, int &right_brk) {
  if (left_brk >= right_brk) {
    
  }
}

vector<string> generateParenthesis(int n) {
  vector<string> vec;
  int left = n;
  int right = n;
  helper(vec, left, right);
  return vec;
}
}  // namespace leetcode