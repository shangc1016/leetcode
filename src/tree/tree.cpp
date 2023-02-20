#include "tree.h"

#include <queue>
#include <vector>

namespace leetcode {

Node* connect(Node* root) {
  //   层序遍历

  if (!root) return nullptr;
  queue<Node*> queue;
  vector<Node*> vec;
  queue.push(root);
  while (!queue.empty()) {
    int sz = queue.size();
    while (sz--) {
      auto ptr = queue.front();
      queue.pop();
      vec.push_back(ptr);
      if (ptr->left) queue.push(ptr->left);
      if (ptr->right) queue.push(ptr->right);
    }
    for (int i = 0; i < vec.size() - 1; i++) {
      vec[i]->next = vec[i+1];
    }
    vec[vec.size() - 1]->next = nullptr;
    vec.clear();
  }
  return root;
}

}  // namespace leetcode