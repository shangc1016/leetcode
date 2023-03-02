#include "sword_to_offer.h"

#include <cstddef>
#include <vector>

namespace leetcode {

vector<int> reversePrint(ListNode* head) {
  if (!head) return {};
  vector<int> vec;
  ListNode* ptr = head;
  while (ptr) {
    vec.push_back(ptr->val);
    ptr = ptr->next;
  }
  int left = 0;
  int right = vec.size() - 1;
  while (left < right) {
    std::swap(vec[left++], vec[right--]);
  }
  return vec;
}

ListNode* reverseList(ListNode* head) {
  ListNode* reverse = nullptr;
  ListNode* ptr = head;
  ListNode* tmp;
  while (ptr) {
    tmp = ptr;
    ptr = ptr->next;
    tmp->next = reverse;
    reverse = tmp;
  }
  return reverse;
}

// 复杂链表的复制
Node* copyRandomList(Node* head) {
  if (!head) return nullptr;
  //   step1、先复制链表

  //   step2、用map把前后两个链表记住
  map<Node*, int> map1;
  vector<Node*> vec;

  Node* dummy1 = new Node(0);
  dummy1->next = head;
  Node* dummy2 = new Node(0);
  Node* ptr = dummy1->next;
  Node* tmp = dummy2;

  int pos = 0;
  while (ptr) {
    tmp->next = new Node(ptr->val);

    map1[ptr] = pos;
    vec.push_back(tmp->next);

    tmp = tmp->next;
    ptr = ptr->next;
  }

  //   step2、复制random指针
  ptr = dummy1->next;
  tmp = dummy2->next;
  while (ptr) {
    if (ptr->random == nullptr)
      tmp->random = nullptr;
    else {
      auto random = ptr->random;
      tmp->random = vec[map1.find(random)->second];
    }
    ptr = ptr->next;
    tmp = tmp->next;
  }
  return dummy2->next;
}

int findRepeatNumber(vector<int>& nums) {
  std::map<int, int> count;
  for (auto item : nums) count[item]++;
  for (auto item : count) {
    if (item.second > 1) return item.first;
  }
  return 0;
}

int search(vector<int>& nums, int target) {
  int count = 0;
  for (auto item : nums) {
    if (item == target) count++;
  }
  return count;
}

int missingNumber(vector<int>& nums) {
  //   正确情况下的总和
  int total = nums.size() * (nums.size() + 1) / 2;
  int sum = 0;
  for (auto item : nums) sum += item;
  return total - sum;
}

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
  if (matrix.empty() || matrix[0].empty()) return false;
  int h = matrix.size();
  int w = matrix[0].size();
  if (target < matrix[0][0] || target > matrix[h - 1][w - 1]) return false;
  int i = h - 1;
  int j = 0;
  while (i >= 0 && j < w) {
    if (matrix[i][j] == target)
      return true;
    else if (matrix[i][j] > target)
      i--;
    else
      j++;
  }
  return false;
}

char firstUniqChar(string s) {
  map<char, int> map;
  for (auto item : s) map[item]++;
  for (auto item : s) {
    if (map[item] == 1) return item;
  }
  return ' ';
}

void helper(TreeNode* root, vector<int>& vec) {
  if (!root) return;
  queue<TreeNode*> queue;
  queue.push(root);
  while (!queue.empty()) {
    auto ptr = queue.front();
    vec.push_back(ptr->val);
    queue.pop();
    if (ptr->left) queue.push(ptr->left);
    if (ptr->right) queue.push(ptr->right);
  }
}
// vector<int> levelOrder(TreeNode* root) {
//   //   层序遍历二叉树
//   vector<int> vec;
//   helper(root, vec);
//   return vec;
// }

void reverse(vector<int>& vec) {
  int left = 0;
  int right = vec.size() - 1;
  while (left < right) swap(vec[left], vec[right]);
}

void helper(TreeNode* root, vector<vector<int>>& vec) {
  if (!root) return;
  queue<TreeNode*> queue;
  queue.push(root);
  int level = 0;
  while (!queue.empty()) {
    int sz = queue.size();
    vector<int> tmp;
    while (sz--) {
      auto ptr = queue.front();
      queue.pop();
      tmp.push_back(ptr->val);
      if (ptr->left) queue.push(ptr->left);
      if (ptr->right) queue.push(ptr->right);
    }
    if (level % 2 == 0)
      vec.push_back(tmp);
    else {
      reverse(tmp);
      vec.push_back(tmp);
    }
    level++;
  }
}

vector<vector<int>> levelOrder(TreeNode* root) {
  vector<vector<int>> vec;
  helper(root, vec);
  return vec;
}

bool sameTree(TreeNode* A, TreeNode* B) {
  //   这儿有(A && !B)是因为A、B相同的部分不一定在叶子上
  if (!A && !B || A && !B)
    return true;
  else if (!A && B || A->val != B->val)
    return false;
  else {
    bool left = sameTree(A->left, B->left);
    bool right = sameTree(A->right, B->right);
    return left && right;
  }
}
bool isSubStructure(TreeNode* A, TreeNode* B) {
  if (!A || !B) return false;
  return sameTree(A, B) || isSubStructure(A->left, B) ||
         isSubStructure(A->right, B);
}

TreeNode* mirrorTree(TreeNode* root) {
  if (!root || !root->left && !root->right) return root;
  auto left = root->left;
  auto right = root->right;
  root->left = right;
  root->right = left;
  mirrorTree(root->left);
  mirrorTree(root->right);
  return root;
}

bool symm(TreeNode* left, TreeNode* right) {
  if (!left && !right) return true;
  if (!left && right || left && !right || left->val != right->val) return false;
  bool l = symm(left->left, right->right);
  bool r = symm(left->right, right->left);
  return l && r;
}

bool isSymmetric(TreeNode* root) {
  if (!root) return true;
  return symm(root->left, root->right);
}

int fib(int n) {
  vector<int> dp(n + 2, 0);
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
  }
  return dp[n];
}

int maxProfit(vector<int>& prices) {
  if (prices.size() <= 1) return 0;
  vector<int> margin(prices.size() - 1, 0);
  for (int i = 0; i < prices.size() - 1; i++) {
    margin[i] = prices[i + 1] - prices[i];
  }

  vector<int> dp(margin.size(), 0);
  dp[0] = margin[0];
  for (int i = 1; i < margin.size(); i++) {
    dp[i] = max(dp[i - 1] + margin[i], margin[i]);
  }
  int max = INT32_MIN;
  for (auto item : dp) {
    if (max < item) max = item;
  }
  return max;
}

int maxSubArray(vector<int>& nums) {
  //   动规问题
  vector<int> dp(nums.size(), 0);
  dp[0] = nums[0];

  int value = nums[0];

  for (int i = 1; i < nums.size(); i++) {
    if (dp[i - 1] + nums[i] < 0)
      dp[i] = nums[i];
    else
      dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    value = dp[i] > value ? dp[i] : value;
  }

  return value;
}

int maxValue(vector<vector<int>>& grid) {
  //   二维dp问题
  if (grid.size() == 0 || grid[0].size() == 0) return 0;

  int h = grid.size();
  int w = grid[0].size();
  vector<vector<int>> dp(h, vector<int>(w, 0));

  dp[0][0] = grid[0][0];

  for (int i = 1; i < h; i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
  for (int i = 1; i < w; i++) dp[0][i] = dp[0][i - 1] + grid[0][i];

  for (int i = 1; i < h; i++) {
    for (int j = 1; j < w; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
    }
  }
  return dp[h - 1][w - 1];
}

ListNode* deleteNode(ListNode* head, int val) {
  if (!head) return nullptr;
  ListNode* dummy = new ListNode(0);
  dummy->next = head;
  auto ptr = dummy;
  while (ptr) {
    if (ptr->next && ptr->next->val == val) {
      auto tmp = ptr->next;
      ptr->next = tmp->next;
      return dummy->next;
    }
    ptr = ptr->next;
  }
  return dummy->next;
}

ListNode* getKthFromEnd(ListNode* head, int k) {
  if (!head) return nullptr;
  auto dummy = new ListNode(0);

  dummy->next = head;
  auto fast = dummy;
  auto slow = head;
  while (fast && k--) fast = fast->next;
  if (!fast) return nullptr;
  while (fast && fast->next) {
    fast = fast->next;
    slow = slow->next;
  }
  return slow;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  if (!l1) return l2;
  if (!l2) return l1;
  ListNode* merge = new ListNode(0);
  ListNode* ptr1 = l1;
  ListNode* ptr2 = l2;
  ListNode* ptr = merge;
  while (l1 && l2) {
    if (l1->val < l2->val) {
      ptr->next = l1;
      l1 = l1->next;
      ptr = ptr->next;
    } else {
      ptr->next = l2;
      l2 = l2->next;
      ptr = ptr->next;
    }
  }
  if (!l1) ptr->next = l2;
  if (!l2) ptr->next = l1;
  return merge->next;
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
  if (!headA || !headB) return nullptr;
  auto ptr1 = headA;
  auto ptr2 = headB;
  while (ptr1 != ptr2) {
    ptr1 = ptr1 ? ptr1->next : headB;
    ptr2 = ptr2 ? ptr2->next : headA;
  }
  return ptr1;
}

string printBin(double num) {
  string str = "0.";
  while (num != 0) {
    num *= 2;
    str += num > 1 ? "1" : "0";
    if (num > 1) num -= 1;
    if (str.size() >= 32 && num != 0) return "ERROR";
  }
  return str;
}

}  // namespace leetcode