#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// https://www.luogu.com.cn/problem/P1305

struct TreeNode {
  char ch_;
  TreeNode* left_{nullptr};
  TreeNode* right_{nullptr};
  TreeNode(char ch) : ch_(ch), left_(nullptr), right_(nullptr) {}
};

void preorder_traverse(TreeNode* root, string& path) {
  if (root == nullptr) return;
  path.push_back(root->ch_);
  preorder_traverse(root->left_, path);
  preorder_traverse(root->right_, path);
}

int main() {
  int N;
  string relation;
  unordered_map<char, TreeNode*> umap;
  unordered_set<char> children;
  unordered_set<char> parents;

  cin >> N;
  while (N--) {
    cin >> relation;
    TreeNode* tree;
    if (umap.find(relation[0]) == umap.end()) {
      tree = new TreeNode(relation[0]);
      umap.insert({relation[0], tree});
    } else {
      tree = umap.find(relation[0])->second;
    }
    parents.insert(relation[0]);

    // 左子树
    if (relation[1] == '*') {
      tree->left_ = nullptr;
    } else {
      if (umap.find(relation[1]) == umap.end()) {
        tree->left_ = new TreeNode(relation[1]);
        umap.insert({relation[1], tree->left_});
      } else {
        tree->left_ = umap.find(relation[1])->second;
      }
      children.insert(relation[1]);
    }
    // 右子树
    if (relation[2] == '*') {
      tree->right_ = nullptr;
    } else {
      if (umap.find(relation[2]) == umap.end()) {
        tree->right_ = new TreeNode(relation[2]);
        umap.insert({relation[2], tree->right_});
      } else {
        tree->right_ = umap.find(relation[2])->second;
      }
      children.insert(relation[2]);
    }
  }

  // 找到根节点，根节点肯定在parent里面，而且不在children里面
  char root_ch;
  for (auto item : parents) {
    if (children.find(item) == children.end()) {
      root_ch = item;
      break;
    }
  }
  string path;
  TreeNode* root = umap.find(root_ch)->second;
  preorder_traverse(root, path);
  cout << path << endl;
}
