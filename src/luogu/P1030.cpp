#include <iostream>
#include <vector>

using namespace std;

// https://www.luogu.com.cn/problem/P1030

struct TreeNode {
  char ch_;
  TreeNode* left_{nullptr};
  TreeNode* right_{nullptr};
  TreeNode(char ch) : ch_(ch), left_(nullptr), right_(nullptr) {}
};

TreeNode* helper(string& in, string post, int is, int it, int ps, int pt) {
  if (is > it) return nullptr;
  char ch = post[pt];
  int cur = is;
  for (int i = is; i <= it; i++) {
    if (in[i] == ch) {
      cur = i;
      break;
    }
  }

  TreeNode* root = new TreeNode(ch);

  root->left_ = helper(in, post, is, cur - 1, ps, ps + cur - is - 1);
  root->right_ = helper(in, post, cur + 1, it, ps + cur - is, pt - 1);
  return root;
}

void preorder_traverse(TreeNode* root, string& pre) {
  if (root == nullptr) return;
  pre.push_back(root->ch_);
  preorder_traverse(root->left_, pre);
  preorder_traverse(root->right_, pre);
}

int main() {
  string preorder;
  string inorder;
  string postorder;

  cin >> inorder;
  cin >> postorder;

  int last = inorder.size() - 1;
  TreeNode* root = helper(inorder, postorder, 0, last, 0, last);
  preorder_traverse(root, preorder);
  cout << preorder << endl;
}
