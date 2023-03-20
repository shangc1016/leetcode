#include "stack.h"

#include <algorithm>
#include <cstdlib>
#include <deque>
#include <queue>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

namespace leetcode {

// 匹配括号
bool isValid(string s) {
  //   奇数一定不对
  if (s.size() % 2 != 0) return false;
  stack<char> stack;
  for (auto item : s) {
    if (item == '(')
      stack.push(')');
    else if (item == '[')
      stack.push(']');
    else if (item == '{')
      stack.push('}');
    else if (stack.empty() || stack.top() != item)
      return false;
    else
      stack.pop();
  }
  return stack.empty();
}

string removeDuplicates(string s) {
  stack<char> stack;
  for (auto item : s) {
    if (stack.empty() || stack.top() != item)
      stack.push(item);
    else if (!stack.empty() && stack.top() == item)
      stack.pop();
  }
  string str;
  while (!stack.empty()) {
    str += stack.top();
    stack.pop();
  }
  reverse(str.begin(), str.end());
  return str;
}

// 逆波兰表达式
int evalRPN(vector<string>& tokens) {
  stack<int> stack;
  int left, right;
  for (auto item : tokens) {
    if (!item.compare("+")) {
      right = stack.top();
      stack.pop();
      left = stack.top();
      stack.pop();
      stack.push(left + right);
    } else if (!item.compare("-")) {
      right = stack.top();
      stack.pop();
      left = stack.top();
      stack.pop();
      stack.push(left - right);
    } else if (!item.compare("*")) {
      right = stack.top();
      stack.pop();
      left = stack.top();
      stack.pop();
      stack.push(left * right);
    } else if (!item.compare("/")) {
      right = stack.top();
      stack.pop();
      left = stack.top();
      stack.pop();
      stack.push(left / right);
    } else {
      stack.push(atoi(item.c_str()));
    }
  }
  return stack.top();
}

// 队列始终保证按照递减的顺序
class MQueue {
 private:
  deque<int> mqueue;

 public:
  void push(int x) {
    // 排序
    while (!mqueue.empty() && mqueue.back() < x) {
      mqueue.pop_back();
    }
    mqueue.push_back(x);
  }

  void pop(int x) {
    // 如果最大的元素已经离开范围，就从队列中除去
    if (!mqueue.empty() && mqueue.front() == x) {
      mqueue.pop_front();
    }
  }

  int front() { return mqueue.front(); }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  vector<int> vec;
  MQueue mqueue;
  for (int i = 0; i < k; i++) mqueue.push(nums[i]);
  vec.push_back(mqueue.front());
  for (int i = k; i < nums.size(); i++) {
    mqueue.pop(nums[i - k]);
    mqueue.push(nums[i]);
    vec.push_back(mqueue.front());
  }
  return vec;
}

class Compare {
 public:
  bool operator()(std::pair<int, int>& A, std::pair<int, int>& B) {
    return A.second < B.second;
  }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
  vector<int> vec;
  unordered_map<int, int> umap;
  priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, Compare>
      queue;
  //   计算频率
  for (auto item : nums) umap[item]++;
  //   入队列
  for (auto item : umap) {
    queue.push({item.first, item.second});
  }
  //   从队列取数
  while (vec.size() < k) {
    auto item = queue.top();
    // cout << item.first << " " << item.second << endl;
    queue.pop();
    vec.push_back(item.first);
  }
  return vec;
}

int longestValidParentheses(string s) {
  stack<char> stack;
  int sz = s.size();
  for (int i = 0; i < sz; i++) {
    if (s[i] == '(')
      stack.push(s[i]);
    else if (s[i] == ')') {
      if (stack.top() == '(') {
        stack.pop();
      }
      else {
        stack.push(')');
      }
    }
  }
  return sz - stack.size();
}

}  // namespace leetcode