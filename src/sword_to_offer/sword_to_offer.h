#ifndef __SWORD_TO_OFFER_
#define __SWORD_TO_OFFER_

#include <algorithm>
#include <array>
#include <cstdint>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

namespace leetcode {

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

vector<int> reversePrint(ListNode* head);

ListNode* reverseList(ListNode* head);

// 复杂链表的复制
Node* copyRandomList(Node* head);

int findRepeatNumber(vector<int>& nums);

int search(vector<int>& nums, int target);

int missingNumber(vector<int>& nums);

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target);

char firstUniqChar(string s);

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// vector<int> levelOrder(TreeNode* root);

// vector<vector<int>> levelOrder(TreeNode* root);

vector<vector<int>> levelOrder(TreeNode* root);

bool isSubStructure(TreeNode* A, TreeNode* B);

TreeNode* mirrorTree(TreeNode* root);

bool isSymmetric(TreeNode* root);

int fib(int n);

int maxProfit(vector<int>& prices);

int maxSubArray(vector<int>& nums);

int maxValue(vector<vector<int>>& grid);

ListNode* deleteNode(ListNode* head, int val);

ListNode* getKthFromEnd(ListNode* head, int k);

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);

string printBin(double num);

}  // namespace leetcode

#endif