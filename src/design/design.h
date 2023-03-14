#ifndef __DESIGN_H_
#define __DESIGN_H_

#include <algorithm>
#include <climits>
#include <cstdarg>
#include <cstddef>
#include <queue>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

namespace design {

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

struct Node {
  Node* next_{nullptr};
  Node* prev_{nullptr};
  int key_;
  int value_;
  Node(int key, int value) : key_(key), value_(value) {}
};

Node* InsertTail(Node* list, Node* node);
Node* RemoveHead(Node* list);
Node* RemoveNode(Node* list, int key);

class LRUCache {
 private:
  vector<std::pair<int, int>> vec;
  
 public:
  LRUCache(int capacity) {}

  int get(int key) { return 0; }

  void put(int key, int value) {}
};
}  // namespace design

#endif