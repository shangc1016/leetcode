

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

namespace leetcode {

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 根据数组构造链表
ListNode* buildList(vector<int>& nums);

// 遍历链表
void traverse(ListNode* head);

// 翻转链表
ListNode* reverse(ListNode* head);


ListNode* removeElements(ListNode* head, int val);

// 翻转链表 https://leetcode.cn/problems/reverse-linked-list/
ListNode* reverseList(ListNode* head);

// 两两交换节点 https://leetcode.cn/problems/swap-nodes-in-pairs/
ListNode* swapPairs(ListNode* head);

// 删除倒数第N个节点
// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
ListNode* removeNthFromEnd(ListNode* head, int n);

// 环形链表
// https://leetcode.cn/problems/linked-list-cycle-ii/
ListNode* detectCycle(ListNode* head);

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);

    class MyLinkedList {
 private:
  ListNode* head;
  ListNode* tail;
  int size;

 public:
  MyLinkedList() {
    head = new ListNode(0);
    tail = head;
    size = 0;
  }

  int get(int index) {
    if (index >= size || index < 0) return -1;
    ListNode* ptr = head->next;
    while (index--) ptr = ptr->next;
    return ptr->val;
  }

  void addAtHead(int val) {
    addAtIndex(0, val);
  }

  void addAtTail(int val) {
   addAtIndex(size, val);
  }

  void addAtIndex(int index, int val) {
    if (index <= 0) {
      // 头部插入
      ListNode* node = new ListNode(val, head->next);
      head->next = node;
      size++;
      if(size == 1) tail = node;

    } else if (0 < index && index < size) {
      // 中间插入
      ListNode* ptr = head;
      while (index--) ptr = ptr->next;
      ListNode* node = new ListNode(val, ptr->next);
      ptr->next = node;
      size++;
    } else if (index == size) {
      // 尾部插入
      ListNode* node = new ListNode(val);
      tail->next = node;
      tail = node;
      size++;
    }
    // index > size 不插入
  }

  void deleteAtIndex(int index) {
    int record = index;
    if (0 <= index && index < size) {
      ListNode* ptr = head;
      while (index--) ptr = ptr->next;
      ListNode* tmp = ptr->next;
      ptr->next = tmp->next;
      tmp->next = nullptr;
      delete tmp;
      if (record == size - 1) {
        tail = head;
        while(tail->next) tail = tail->next;
      }
      size --;
    }
  }

  void print() {
    ListNode* ptr = head->next;
    while (ptr) {
      std::cout << ptr->val << " ";
      ptr = ptr->next;
    }
    std::cout << "; size = " << size << std::endl;
  }
};
}  // namespace leetcode