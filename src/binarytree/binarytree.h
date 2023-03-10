#ifndef __BINARYTREE_H_
#define __BINARYTREE_H_

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

namespace leetcode {

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Codec {
 private:
  void preorder(TreeNode *root, vector<int> &pre) {
    if (!root) return;
    pre.push_back(root->val);
    preorder(root->left, pre);
    preorder(root->right, pre);
  }

  void inorder(TreeNode *root, vector<int> &in) {
    if (!root) return;
    inorder(root->left, in);
    in.push_back(root->val);
    inorder(root->right, in);
  }

 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (!root) return "";
    vector<int> pre, in;
    preorder(root, pre);
    inorder(root, in);
    string str;
    str += to_string(pre[0]);
    for (int i = 1; i < pre.size(); i++) str += "," + to_string(pre[i]);
    str += '*';
    str += to_string(in[0]);
    for (int i = 1; i < in.size(); i++) str += "," + to_string(in[i]);
    return str;
  }

  TreeNode *buildTree(vector<int> &pre, vector<int> &in, int pstart, int pend,
                      int istart, int iend) {
    if (pstart > pend || istart > iend) return nullptr;

    TreeNode *root = new TreeNode(pre[pstart]);

    int index = istart;
    for (int i = istart; i <= iend; i++) {
      if (in[i] == pre[pstart]) {
        index = i;
        break;
      }
    }

    root->left = buildTree(pre, in, pstart + 1, pstart + index - istart, istart,
                           index - 1);
    root->right =
        buildTree(pre, in, pstart + index - istart + 1, pend, index + 1, iend);

    return root;
  }

  vector<int> split(string str) {
    int pos;
    vector<int> vec;
    while ((pos = str.find(',')) >= 0) {
      vec.push_back(stoi(str.substr(0, pos)));
      str = str.substr(pos + 1);
    }
    vec.push_back(stoi(str));
    return vec;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    if (data.empty()) return nullptr;
    int pos = data.find('*');
    string pre = data.substr(0, pos);
    string in = data.substr(pos + 1);
    vector<int> prevec, invec;
    prevec = split(pre);
    invec = split(in);

    return buildTree(prevec, invec, 0, prevec.size() - 1, 0, invec.size() - 1);
  }
};

// class Solution {
//  private:
//   vector<vector<int>> result;
//   void backtracing(TreeNode *root, int targetSum, vector<int> &vec) {
//     if (!root) return;
//     if (!root->left && !root->right && targetSum == root->val) {
//       result.push_back(vec);
//       return;
//     }
//     vec.push_back(root->val);
//     backtracing(root->left, targetSum - root->val, vec);
//     backtracing(root->right, targetSum - root->val, vec);
//   }

//  public:
//   vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
//     vector<int> vec;
//     backtracing(root, targetSum, vec);
//     return result;
//   }
// };

class BSTIterator {
 private:
  vector<int> inorder;
  int index;
  void inOrder(TreeNode *root, vector<int> &in) {
    if (!root) return;
    inOrder(root->left, in);
    in.push_back(root->val);
    inOrder(root->right, in);
  }

 public:
  BSTIterator(TreeNode *root) {
    inOrder(root, inorder);
    index = 0;
  }

  int next() { return inorder[index++]; }

  bool hasNext() { return index < inorder.size(); }
};

class Solution {
 private:
  int partSum;
  int helper(TreeNode *root) {
    if (!root) return -1000;
    if (!root->left && !root->right) return root->val;
    int left = helper(root->left);
    int right = helper(root->right);
    int val = root->val;
    partSum = max({left, right, val, left + val, right + val,
                   left + val + right, partSum});
    return partSum;
  }

 public:
  int maxPathSum(TreeNode *root) {
    partSum = -1000;
    return helper(root);
  }
};

TreeNode *invertTree(TreeNode *root);

bool isSymmetric(TreeNode *root);

bool isSameTree(TreeNode *p, TreeNode *q);

bool isSubtree(TreeNode *root, TreeNode *subRoot);

int maxDepth(TreeNode *root);

int minDepth(TreeNode *root);

int countNodes(TreeNode *root);

bool isBalanced(TreeNode *root);

vector<string> binaryTreePaths(TreeNode *root);

int sumOfLeftLeaves(TreeNode *root);

int findBottomLeftValue(TreeNode *root);

bool hasPathSum(TreeNode *root, int targetSum);

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder);

TreeNode *constructMaximumBinaryTree(vector<int> &nums);

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2);

TreeNode *searchBST(TreeNode *root, int val);

bool isValidBST(TreeNode *root);

int getMinimumDifference(TreeNode *root);

vector<int> findMode(TreeNode *root);

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);

TreeNode *insertIntoBST(TreeNode *root, int val);

TreeNode *deleteNode(TreeNode *root, int key);

TreeNode *trimBST(TreeNode *root, int low, int high);

TreeNode *sortedArrayToBST(vector<int> &nums);

TreeNode *convertBST(TreeNode *root);

int numTrees(int n);

void recoverTree(TreeNode *root);

int maxPathSum(TreeNode *root);

int rob(TreeNode *root);

vector<int> findFrequentTreeSum(TreeNode *root);

int findTilt(TreeNode *root);

int widthOfBinaryTree(TreeNode *root);

int maxPathSum(TreeNode *root);
}  // namespace leetcode

#endif