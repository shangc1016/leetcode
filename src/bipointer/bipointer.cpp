#include "bipointer.h"

#include <iostream>
#include <utility>
namespace bipointer {

void reverseRange(string &str, int left, int right) {
  while (left < right) {
    std::swap(str[left++], str[right--]);
  }
}
// 单词翻转
string reverseWords(string s) {
  //   1. trim
  int left = 0;
  int right = s.size() - 1;
  while (s[left] == ' ') left++;
  while (s[right] == ' ') right--;

  string trim;
  for (int i = left; i <= right; i++) {
    if (trim.back() == ' ' && s[i] == ' ') continue;
    trim.push_back(s[i]);
  }
  reverseRange(trim, 0, trim.size() - 1);

  left = 0;
  right = 0;
  while (left <= right && right < trim.size()) {
    while (left <= right && right < trim.size() && trim[right] != ' ') right++;
    reverseRange(trim, left, right - 1);
    right++;
    left = right;
  }
  cout << trim << endl;
  return trim;
}
}  // namespace bipointer
