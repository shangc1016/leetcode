// https://www.luogu.com.cn/problem/P4913

#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
  int val_;
  TreeNode* left_;
  TreeNode* right_;
  TreeNode(int val) : val_(val), left_(nullptr), right_(nullptr) {}
};

int depth(TreeNode* root) {
  if (root == nullptr) return 0;
  int l = depth(root->left_);
  int r = depth(root->right_);
  return max(l, r) + 1;
}

int main() {
  //

  int n;
  cin >> n;

  unordered_map<int, TreeNode*> umap;
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    TreeNode* root;
    if (umap.find(i) == umap.end()) {
      root = new TreeNode(i);
      umap.insert({i, root});
    } else {
      root = umap.find(i)->second;
    }

    if (l == 0) {
      root->left_ = nullptr;
    } else {
      if (umap.find(l) == umap.end()) {
        root->left_ = new TreeNode(l);
        umap.insert({l, root->left_});
      } else {
        root->left_ = umap.find(l)->second;
      }
    }

    if (r == 0) {
      root->right_ = nullptr;
    } else {
      if (umap.find(r) == umap.end()) {
        root->right_ = new TreeNode(r);
        umap.insert({r, root->right_});
      } else {
        root->right_ = umap.find(r)->second;
      }
    }
  }

  auto root = umap.find(1)->second;

  cout << depth(root) << endl;
  //
  return 0;
}