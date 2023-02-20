#include "greedy.h"

#include <algorithm>

namespace leetcode {

int findContentChildren(vector<int>& g, vector<int>& s) {
  sort(g.begin(), g.end());
  sort(s.begin(), s.end());
  int count = 0;
  int i = 0, j = 0;
  while (i < g.size() && j < s.size()) {
    if (s[j] >= g[i]) {
      count++;
      i++;
      j++;
    } else {
      j++;
    }
  }
  return count;
}

int wiggleMaxLength(vector<int>& nums) {
  if (nums.size() < 2) return 0;
  if (nums.size() == 2 && nums[0] == nums[1]) return 0;
  int count = 0;
  for (int i = 1; i < nums.size() - 1; i++) {
    
  }
  return count;
}

}  // namespace leetcode