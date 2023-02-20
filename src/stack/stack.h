
#include <iostream>
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

}  // namespace leetcode
