#ifndef __DESIGN_H_
#define __DESIGN_H_

#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
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

  void appendTail(int value) { first.push(value); }

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

class MinStack {
 private:
  std::stack<int> stackA;
  std::stack<int> stackB;

 public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    stackA.push(x);
    if (stackB.empty() || x <= stackB.top()) stackB.push(x);
  }

  void pop() {
    int top = stackA.top();
    stackA.pop();
    if (top == stackB.top()) stackB.pop();
  }

  int top() { return stackA.top(); }

  int min() { return stackB.top(); }
};
}  // namespace leetcode

#endif