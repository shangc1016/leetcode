#include "istring.h"

#include <algorithm>
#include <stack>
#include <string>

namespace leetcode {

void reverseString(vector<char>& s) {
  //   双指针
  int left = 0;
  int right = s.size() - 1;
  while (left < right) {
    swap(s[left++], s[right--]);
  }
}

string reverseStr(string s, int k) {
  for (int i = 0; i < s.size(); i += 2 * k) {
    if (i + k < s.size())
      reverse(s.begin() + i, s.begin() + i + k);
    else
      reverse(s.begin() + i, s.end());
  }
  return s;
}

string replaceSpace(string s) {
  string str;
  for (auto item : s) {
    if (item != ' ')
      str += item;
    else
      str += "%20";
  }
  return str;
}

// string reverseWords(string s) {
//   //   空格分割，
//   //   the sky is blue ->  blue is sky the
//   stack<string> stack;
//   int slow = 0;
//   int fast = 0;
//   while (fast < s.size()) {
//     while (fast < s.size() && s[fast] != ' ' && s[fast + 1] != ' ') fast++;
//   }
// }

// 左旋字符串
string reverseLeftWords(string s, int n) {
  n = n % s.size();
  string str;
  for (int i = n; i < s.size(); i++) str += s[i];
  for (int i = 0; i < n; i++) str += s[i];
  return str;
}

}  // namespace leetcode