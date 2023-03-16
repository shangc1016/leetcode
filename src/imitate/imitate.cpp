#include "imitate.h"

#include <stack>

namespace imitate {

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
  if (pushed.empty() && popped.empty()) return true;
  if (pushed.size() != popped.size()) return false;
  int i = 0, j = 0;
  stack<int> stack;
  while (i < popped.size() && j < popped.size()) {
    if (pushed[i] == popped[j]) {
      i++;
      j++;
    } else if (!stack.empty() && stack.top() == popped[j]) {
      stack.pop();
      j++;
    } else {
      stack.push(pushed[i]);
      i++;
    }
  }
  while (!stack.empty() && j < popped.size()) {
    if (stack.top() == popped[j]) {
      stack.pop();
      j++;
    } else {
      return false;
    }
  }
  return true;
}

}  // namespace imitate