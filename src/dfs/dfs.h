#ifndef __DFS_H_
#define __DFS_H_

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
namespace dfs {
class Solution {
 private:
  string result;
  vector<string> vec;

  void helper(string str) {
    if (str.empty()) return;

    queue<string> queue;
    queue.push(str);
    while (!queue.empty()) {
      string front = queue.front();
      queue.pop();
      string reverse = string(front.rbegin(), front.rend());
      if (reverse == front) {
        result = front;
        return;
      }

      string left = front.substr(1);
      string right = front.substr(0, str.size() - 1);
      cout << "left = " << left << endl;
      cout << "right = " << right << endl;
      if (!left.empty()) queue.push(left);
      if (!right.empty()) queue.push(right);
    }
  }

 public:
  string longestPalindrome(string s) {
    helper(s);
    return result;
  }
};
}  // namespace dfs

#endif