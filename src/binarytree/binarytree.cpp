#include "binarytree.h"

#include <algorithm>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

namespace leetcode {

TreeNode *invertTree(TreeNode *root) {
  if (!root) return nullptr;
  std::swap(root->left, root->right);
  invertTree(root->left);
  invertTree(root->right);
  return root;
}

// bool helper(TreeNode *left, TreeNode *right) {
//   if (!left && !right)
//     return true;
//   else if (!left && right || left && !right)
//     return false;
//   else {
//     if (left->val != right->val) return false;
//     return helper(left->left, right->right) && helper(left->right,
//     right->left);
//   }
// }
// bool isSymmetric(TreeNode *root) {
//   if (!root) return true;
//   return helper(root->left, root->right);
// }

bool isSameTree(TreeNode *p, TreeNode *q) {
  if (!p && !q) return true;
  if (p && q && p->val == q->val)
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  else
    return false;
}

bool isSubtree(TreeNode *root, TreeNode *subRoot) {
  if (!root) return false;
  if (isSameTree(root, subRoot)) return true;
  return isSameTree(root->left, subRoot) || isSameTree(root->right, subRoot);
}

int minDepth(TreeNode *root) {
  if (!root) return 0;
  if (!root->left && !root->right) return 1;
  if (!root->left) return minDepth(root->right) + 1;
  if (!root->right) return minDepth(root->left) + 1;
  int left = minDepth(root->left);
  int right = minDepth(root->right);
  return left > right ? right + 1 : left + 1;
}

int countNodes(TreeNode *root) {
  if (!root) return 0;
  return countNodes(root->left) + countNodes(root->right) + 1;
}

bool isBalanced(TreeNode *root) {
  if (!root) return true;
  int left = maxDepth(root->left);
  int right = maxDepth(root->right);
  if (abs(left - right) > 1) return false;
  return isBalanced(root->left) && isBalanced(root->right);
}

void help(TreeNode *root, string part, vector<string> &vec) {
  if (!root) return;
  if (!root->left && !root->right) {
    part += to_string(root->val);
    vec.push_back(part);
  }
  part += to_string(root->val);
  if (root->left) help(root->left, part + "->", vec);
  if (root->right) help(root->right, part + "->", vec);
}

vector<string> binaryTreePaths(TreeNode *root) {
  vector<string> vec;
  if (!root) return vec;
  help(root, "", vec);
  return vec;
}

void helper(TreeNode *root, int left, int &sum) {
  if (!root) return;
  if (!root->left && !root->right && left == 1) sum += root->val;
  helper(root->left, 1, sum);
  helper(root->right, 0, sum);
}

int sumOfLeftLeaves(TreeNode *root) {
  int sum = 0;
  helper(root, 0, sum);
  return sum;
}

int maxDepth(TreeNode *root) {
  if (!root) return 0;
  int left = maxDepth(root->left);
  int right = maxDepth(root->right);
  return left > right ? left + 1 : right + 1;
}

int findBottomLeftValue(TreeNode *root) {
  // 层序遍历，最后一层第一个元素
  queue<TreeNode *> queue;
  int depth = maxDepth(root);
  queue.push(root);
  while (!queue.empty()) {
    int sz = queue.size();
    depth--;
    if (depth == 0) return queue.front()->val;
    while (sz--) {
      auto ptr = queue.front();
      queue.pop();
      if (ptr->left) queue.push(ptr->left);
      if (ptr->right) queue.push(ptr->right);
    }
  }
  return 0;
}

bool hasPathSum(TreeNode *root, int targetSum) {
  if (!root) return false;
  if (!root->left && !root->right && targetSum == root->val) return true;
  bool left = hasPathSum(root->left, targetSum - root->val);
  bool right = hasPathSum(root->right, targetSum - root->val);
  return left || right;
}

// 中、后构造二叉树
// 后顺遍历二叉树，最后一个是根节点
TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int istart,
                 int iend, int pstart, int pend) {
  if (istart > iend || pstart > pend) return nullptr;

  TreeNode *root = new TreeNode(postorder[pend]);

  int index = istart;
  for (int i = istart; i <= iend; i++) {
    if (inorder[i] == postorder[pend]) {
      index = i;
      break;
    }
  }
  // 3
  root->left = helper(inorder, postorder, istart, index - 1, pstart,
                      pstart + index - istart - 1);
  root->right = helper(inorder, postorder, index + 1, iend,
                       pstart + index - istart, pend - 1);
  return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
  return helper(inorder, postorder, 0, inorder.size() - 1, 0,
                postorder.size() - 1);
}

TreeNode *helper(vector<int> &nums, int left, int right) {
  if (left > right) return nullptr;
  int maxIndex = left;
  for (int i = left; i <= right; i++) {
    if (nums[maxIndex] < nums[i]) maxIndex = i;
  }
  TreeNode *root = new TreeNode(nums[maxIndex]);
  root->left = helper(nums, left, maxIndex - 1);
  root->right = helper(nums, maxIndex + 1, right);
  return root;
}

TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
  return helper(nums, 0, nums.size() - 1);
}

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
  if (!root1) return root2;
  if (!root2) return root1;
  root1->val += root2->val;
  root1->left = mergeTrees(root1->left, root2->left);
  root1->right = mergeTrees(root1->right, root2->right);
  return root1;
}

TreeNode *searchBST(TreeNode *root, int val) {
  if (!root) return nullptr;
  if (root->val > val)
    return searchBST(root->left, val);
  else if (root->val < val)
    return searchBST(root->right, val);
  else
    return root;
}

bool valid(TreeNode *root, long left, long right) {
  if (!root) return true;
  if (root->val <= left || root->val >= right) return false;
  bool l = valid(root->left, left, root->val);
  bool r = valid(root->right, root->val, right);
  return l && r;
}

bool isValidBST(TreeNode *root) { return valid(root, LONG_MIN, LONG_MAX); }

void inorder(TreeNode *root, vector<int> &nums) {
  if (!root) return;
  inorder(root->left, nums);
  nums.push_back(root->val);
  inorder(root->right, nums);
}

int getMinimumDifference(TreeNode *root) {
  vector<int> nums;
  inorder(root, nums);
  sort(nums.begin(), nums.end());
  int diff = INT_MAX;
  for (int i = 0; i < nums.size() - 1; i++) {
    diff = min(diff, nums[i + 1] - nums[i]);
  }
  return diff;
}

void in(TreeNode *root, unordered_map<int, int> &map, int &frequent) {
  if (!root) return;
  in(root->left, map, frequent);
  map[root->val]++;
  if (map[root->val] > frequent) frequent = map[root->val];
  in(root->right, map, frequent);
}

vector<int> findMode(TreeNode *root) {
  unordered_map<int, int> umap;
  int count = 0;
  in(root, umap, count);

  vector<int> vec;
  for (auto it = umap.begin(); it != umap.end(); it++) {
    if (it->second == count) vec.push_back(it->first);
  }
  return vec;
}

bool contain(TreeNode *root, TreeNode *p) {
  if (!root) return false;
  if (root == p) return true;
  bool left = contain(root->left, p);
  bool right = contain(root->right, p);
  return left || right;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
  if (!root) return nullptr;
  if (p == root || q == root) return root;
  bool posP = contain(root->left, p);
  bool posQ = contain(root->left, q);
  if (posP && posQ) {
    return lowestCommonAncestor(root->left, p, q);
  } else if (!posP && !posQ) {
    return lowestCommonAncestor(root->right, p, q);
  } else {
    return root;
  }
}

// TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
//   if (!root) return nullptr;
//   if (p == root || q == root) return root;
//   if (p->val < root->val && q->val < root->val)
//     return lowestCommonAncestor(root->left, p, q);
//   else if (p->val > root->val && q->val > root->val)
//     return lowestCommonAncestor(root->right, p, q);
//   else
//     return root;
// }

TreeNode *insertIntoBST(TreeNode *root, int val) {
  if (!root) return new TreeNode(val);
  if (val <= root->val)
    root->left = insertIntoBST(root->left, val);
  else
    root->right = insertIntoBST(root->right, val);
  return root;
}

TreeNode *deleteNode(TreeNode *root, int key) {
  if (!root) return nullptr;
  if (root->val > key)
    root->left = deleteNode(root->left, key);
  else if (root->val < key)
    root->right = deleteNode(root->right, key);
  else {
    // 删除节点就是本节点root
    if (!root->left && !root->right) {
      delete root;
      return nullptr;
    } else if (root->left) {
      // 找到左子树的最右节点
      TreeNode *ptr = root->left;
      while (ptr->right) ptr = ptr->right;
      int tmp = root->val;
      root->val = ptr->val;
      ptr->val = tmp;
      root->left = deleteNode(root->left, key);

    } else {
      TreeNode *ptr = root->right;
      while (ptr->left) ptr = ptr->left;
      int tmp = root->val;
      root->val = ptr->val;
      ptr->val = tmp;
      root->right = deleteNode(root->right, key);
    }
  }
  return root;
}

TreeNode *trimBST(TreeNode *root, int low, int high) {
  if (!root) return nullptr;
  if (root->val < low) {
    auto right = trimBST(root->right, low, high);
    return right;
  }
  if (root->val > high) {
    auto left = trimBST(root->left, low, high);
    return left;
  }
  root->left = trimBST(root->left, low, high);
  root->right = trimBST(root->right, low, high);
  return root;
}

TreeNode *hhelp(vector<int> &nums, int left, int right) {
  if (left > right) return nullptr;
  int mid = left + (right - left) / 2;
  TreeNode *root = new TreeNode(nums[mid]);
  root->left = hhelp(nums, left, mid - 1);
  root->right = hhelp(nums, mid + 1, right);
  return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums) {
  return hhelp(nums, 0, nums.size() - 1);
}

void helper_convert(TreeNode *root, int &val) {
  if (!root) return;
  helper_convert(root->right, val);
  root->val += val;
  val = root->val;
  helper_convert(root->left, val);
}
TreeNode *convertBST(TreeNode *root) {
  int val = 0;
  helper_convert(root, val);
  return root;
}

int numTrees(int n) {
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  dp[1] = 1;

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      dp[i] += dp[j] * dp[i - j - 1];
    }
  }
  return dp[n];
}

void inorderTraverse(TreeNode *root, vector<TreeNode *> &vec) {
  if (!root) return;
  inorderTraverse(root->left, vec);
  vec.push_back(root);
  inorderTraverse(root->right, vec);
}
void recoverTree(TreeNode *root) {
  vector<TreeNode *> vec;
  inorderTraverse(root, vec);
  // 原地排序
  for (int i = 0; i < vec.size(); i++) {
    for (int j = i; j < vec.size(); j++) {
      if (vec[i]->val > vec[j]->val) {
        swap(vec[i]->val, vec[j]->val);
      }
    }
  }
}

int helper(TreeNode *root, int &val) {
  if (!root) return -1000;
  int left = helper(root->left, val);
  int right = helper(root->right, val);
  cout << "left =" << left << endl;
  cout << "right =" << right << endl;

  val = max({val, left, right, root->val, left + root->val, root->val + right,
             left + right + root->val});
  return val;
}

int maxPathSum(TreeNode *root) {
  int val = -1000;
  helper(root, val);
  return val;
}

void helper(TreeNode *root, int &odd, int &even) {
  int level = 0;
  if (!root) return;
  queue<TreeNode *> queue;
  queue.push(root);
  while (!queue.empty()) {
    int sz = queue.size();
    while (sz--) {
      auto ptr = queue.front();
      queue.pop();
      if (level % 2 == 0)
        even += max(0, ptr->val);
      else
        odd += max(0, ptr->val);
      if (ptr->left) queue.push(ptr->left);
      if (ptr->right) queue.push(ptr->right);
    }
    level++;
  }
}

int rob(TreeNode *root) {
  int odd = 0;
  int even = 0;
  helper(root, odd, even);
  return odd > even ? odd : even;
}

int hhelper(TreeNode *root, map<int, int> &map) {
  if (!root) return 0;
  if (!root->left && !root->right) {
    map[root->val]++;
    return root->val;
  }
  int left = hhelper(root->left, map);
  int right = hhelper(root->right, map);
  map[left + right + root->val]++;
  return left + right + root->val;
}

vector<int> findFrequentTreeSum(TreeNode *root) {
  map<int, int> map;
  vector<int> vec;
  hhelper(root, map);
  int freq = 0;
  for (auto item : map) {
    if (item.second > freq) freq = item.second;
  }
  for (auto item : map) {
    if (item.second == freq) vec.push_back(item.first);
  }
  return vec;
}

int helper1(TreeNode *root, int &val) {
  if (!root) return 0;
  if (!root->left && !root->right) return root->val;

  int left = helper1(root->left, val);
  int right = helper1(root->right, val);
  val += abs(left - right);
  return left + right + root->val;
}

int findTilt(TreeNode *root) {
  int val = 0;
  helper1(root, val);
  return val;
}

int widthOfBinaryTree(TreeNode *root) {
  if(!root) return 0;
  int width = 0;
  queue<TreeNode *> queue;
  queue.push(root);
  while (!queue.empty()) {
    int sz = queue.size();
    if (width < sz) width = sz;
    while (sz--) {
      auto ptr = queue.front();
      if(!ptr) continue;
      queue.pop();
      queue.push(ptr->left);
      queue.push(ptr->right);
    }
  }
  return width;
}

}  // namespace leetcode