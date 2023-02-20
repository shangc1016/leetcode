#ifndef __DESIGN_H_
#define __DESIGN_H_

#include <climits>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <utility>

using namespace std;

namespace leetcode {

class CQueue {
 private:
  stack<int> first;
  stack<int> second;
 public:
  CQueue() {}

  void appendTail(int value) {
    first.push(value);
  }

  int deleteHead() {
    if (first.empty() && second.empty()) return -1;
    if (!second.empty()) {
      int val = second.top();
      second.pop();
      return val;
    } else {
      while (!first.empty()) {
        second.push(first.top());
        first.pop();
      }
      int val = second.top();
      second.pop();
      return val;
    }
  }
};
}

#endif