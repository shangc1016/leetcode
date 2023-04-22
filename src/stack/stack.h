
#include <cstdint>
#include <iostream>
#include <map>
#include <ostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

namespace leetcode {

// 匹配括号
bool isValid(string s);

string removeDuplicates(string s);

int evalRPN(vector<string>& tokens);

vector<int> maxSlidingWindow(vector<int>& nums, int k);

vector<int> topKFrequent(vector<int>& nums, int k);

int longestValidParentheses(string s);

// 用栈实现队列
class MyQueue {
 private:
  std::stack<int> stack1;
  std::stack<int> stack2;

 public:
  MyQueue() {}

  void push(int x) { stack1.push(x); }

  int pop() {
    if (stack2.empty()) {
      //   把stack1的元素全部放到stack2
      while (!stack1.empty()) {
        stack2.push(stack1.top());
        stack1.pop();
      }
    }
    int val = stack2.top();
    stack2.pop();
    return val;
  }

  int peek() {
    if (stack2.empty()) {
      //   把stack1的元素全部放到stack2
      while (!stack1.empty()) {
        stack2.push(stack1.top());
        stack1.pop();
      }
    }
    return stack2.top();
  }

  bool empty() { return stack1.empty() && stack2.empty(); }
};

// 用队列实现栈
// 这个和用栈模拟队列不同，在那种情况下，两个栈是有先后顺序的，功能不同。
// 在现在的情况中，两个队列是平等的。
class MyStack {
 private:
  std::queue<int> queue1;
  std::queue<int> queue2;

 public:
  MyStack() {}

  void push(int x) {
    if (queue1.empty()) queue2.push(x);
    if (queue2.empty()) queue1.push(x);
  }

  int pop() {
    if (queue1.empty()) {
      while (queue2.size() > 1) {
        queue1.push(queue2.front());
        queue2.pop();
      }
      int val = queue2.front();
      queue2.pop();
      return val;
    } else if (queue2.empty()) {
      while (queue1.size() > 1) {
        queue2.push(queue1.front());
        queue1.pop();
      }
      int val = queue1.front();
      queue1.pop();
      return val;
    }
    return 0;
  }

  int top() {
    if (queue1.empty()) {
      while (queue2.size() > 1) {
        queue1.push(queue2.front());
        queue2.pop();
      }
      int val = queue2.front();
      queue2.pop();
      queue1.push(val);
      return val;
    } else if (queue2.empty()) {
      while (queue1.size() > 1) {
        queue2.push(queue1.front());
        queue1.pop();
      }
      int val = queue1.front();
      queue1.pop();
      queue1.push(val);
      return val;
    }
    return 0;
  }

  bool empty() { return queue1.empty() && queue2.empty(); }
};

class MinStack {
 private:
  stack<int> stack_;
  stack<int> min_stack_;

 public:
  MinStack() { min_stack_.push(INT32_MAX); }

  void push(int val) {
    stack_.push(val);
    min_stack_.push(min(min_stack_.top(), val));
  }

  void pop() {
    stack_.pop();
    min_stack_.pop();
  }

  int top() { return stack_.top(); }

  int getMin() { return min_stack_.top(); }
};

class Solution_394 {
 private:
 public:
  string decodeString(string s) {
    stack<int> num_stack;
    stack<string> str_stack;

    int count = 0;
    string str;
    for (int i = 0; i < s.size(); i++) {
      if ('0' <= s[i] && s[i] <= '9') {
        count = count * 10 + (s[i] - '0');
      } else if (s[i] == '[') {
        num_stack.push(count);
        str_stack.push(str);
        str.clear();
        count = 0;
      } else if (s[i] == ']') {
        int sz = num_stack.top();
        num_stack.pop();
        string temp;
        temp += str_stack.top();
        str_stack.pop();
        while (sz--) temp += str;
        str = temp;
        count = 0;
      } else {
        str += s[i];
      }
    }
    return str;
  }
};

class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    map<Node*, bool> map;
    if (node == nullptr) return nullptr;
    std::queue<Node*> queue;
    std::queue<Node*> newQueue;
    Node* newNode = new Node(node->val);
    queue.push(node);
    newQueue.push(newNode);
    while (!queue.empty()) {
      Node* ptr = queue.front();
      Node* newPtr = newQueue.front();
      map[ptr] = true;
      queue.pop();
      newQueue.pop();
      for (auto child : ptr->neighbors) {
        if (map.find(child) == map.end()) {
          auto newNode = new Node(child->val);
          newPtr->neighbors.push_back(newNode);
          newQueue.push(newNode);
          queue.push(child);
        }
      }
    }
    return newNode;
  }
};

}  // namespace leetcode
