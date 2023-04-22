#include <math.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// https://www.luogu.com.cn/problem/P4715

// 数组建树

struct TreeNode {
  int val_;
  int order_;
  TreeNode* left_;
  TreeNode* right_;
  TreeNode(int val, int order)
      : val_(val), order_(order), left_(nullptr), right_(nullptr) {}
};

int main() {
  int n;
  cin >> n;

  queue<TreeNode*> Q;
  for (int i = 0; i < pow(2, n); i++) {
    int tmp;
    cin >> tmp;
    Q.push(new TreeNode(tmp, i));
  }

  while (Q.size() > 1) {
    int sz = Q.size();
    for (int i = 0; i < sz / 2; i++) {
      TreeNode* left = Q.front();
      Q.pop();
      TreeNode* right = Q.front();
      Q.pop();
      int val, order;
      if (left->val_ > right->val_) {
        val = left->val_;
        order = left->order_;
      } else {
        val = right->val_;
        order = right->order_;
      }
      TreeNode* root = new TreeNode(val, order);
      root->left_ = left;
      root->right_ = right;
      Q.push(root);
    }
  }

  auto root = Q.front();
  Q.pop();
  int val, order;
  if (root->left_->val_ > root->right_->val_) {
    cout << root->right_->order_ + 1 << endl;
  } else {
    cout << root->left_->order_ + 1 << endl;
  }

  return 0;
}