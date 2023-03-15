#ifndef __BIPOINTER_H_
#define __BIPOINTER_H_

#include <string>
#include <vector>
using namespace std;
namespace bipointer {

string reverseWords(string s);

class Solution {
 private:
  int count;

  void helper(vector<int>& nums, int k, int startIndex) {
    if (startIndex == nums.size()) return;
    int sum = 0;
    int left = startIndex, right = startIndex;
    while (left <= right && right < nums.size()) {
      if (sum < k) {
        sum += nums[right];
        right++;
      }
      if (sum > k) {
        sum -= nums[left];
        left++;
      }
      if (sum == k) {
        count++;
        sum -= nums[left++];
      }
    }
  }

 public:
  int subarraySum(vector<int>& nums, int k) {
    if (nums.size() == 1 && nums[0] != k) return 0;
    for (int i = 0; i < nums.size(); i++) {
      helper(nums, k, 0);
    }
    return count;
  }
};

}  // namespace bipointer

#endif