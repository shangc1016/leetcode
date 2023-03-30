#include "list.h"

#include <cmath>
#include <cstddef>
#include <cstdio>
#include <ios>
#include <iostream>
#include <vector>

namespace leetcode {

ListNode* buildList(vector<int>& nums) {
  ListNode* head = nullptr;
  ListNode* ptr;
  for (int i = nums.size() - 1; i >= 0; --i) {
    // cout << nums[i] << endl;
    ptr = new ListNode(nums[i]);
    ptr->next = head;
    head = ptr;
    // cout << nums[i] << endl;
  }
  return head;
}

ListNode* reverse(ListNode* head) {
  if (head == nullptr) return nullptr;
  // 从原来链表的头取下节点，然后在新的链表头部插入
  ListNode* newHead = nullptr;
  ListNode* ptr;
  while (head) {
    ptr = head;
    head = head->next;
    ptr->next = newHead;
    newHead = ptr;
  }
  return newHead;
}

// 一眼双指针问题
// 主要是在于在链表的头，添加一个临时的节点，方便代码
ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode* prefix = new ListNode(0, head);
  ListNode* fast = head;
  ListNode* slow = prefix;
  while (fast && n--) fast = fast->next;
  while (fast) {
    fast = fast->next;
    slow = slow->next;
  }
  ListNode* tmp = slow->next;
  slow->next = tmp->next;
  tmp->next = nullptr;
  delete tmp;
  head = prefix->next;
  prefix->next = nullptr;
  delete prefix;
  return head;
}

// 链表相交  https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/
// 双指针方法
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
  if (!headA && !headB) return nullptr;
  ListNode* ptrA = headA;
  ListNode* ptrB = headB;
  while (ptrA != ptrB) {
    if (!ptrA)
      ptrA = headB;
    else
      ptrA = ptrA->next;

    if (!ptrB)
      ptrB = headA;
    else
      ptrB = ptrB->next;
    if (!ptrA && !ptrB) break;
  }
  return ptrA;
}

// 链表的环形检测，双指针 https://leetcode.cn/problems/linked-list-cycle-ii/
ListNode* detectCycle(ListNode* head) {
  if (!head || !head->next) return nullptr;
  ListNode* fast = head;
  ListNode* slow = head;
  while (fast && slow) {
    if (!fast->next || !fast->next->next) break;
    fast = fast->next->next;
    if (!slow->next) break;
    slow = slow->next;
    if (fast == slow) break;
  }
  if (!fast->next || !fast->next->next || !slow->next) return nullptr;
  fast = head;
  while (fast != slow) {
    fast = fast->next;
    slow = slow->next;
  }
  return fast;
}

// 移除链表元素https://leetcode.cn/problems/remove-linked-list-elements/
ListNode* removeElements(ListNode* head, int val) {
  if (head == nullptr) return nullptr;
  ListNode* newHead = new ListNode(0, head);
  ListNode* ptr = newHead;
  while (ptr->next) {
    if (ptr->next->val == val) {
      ListNode* tmp = ptr->next;
      ptr->next = tmp->next;
      tmp->next = nullptr;
      delete tmp;
    } else {
      ptr = ptr->next;
    }
  }
  return newHead->next;
}

ListNode* reverseList(ListNode* head) {
  if (head == nullptr) return nullptr;
  // 从原来链表的头取下节点，然后在新的链表头部插入
  ListNode* newHead = nullptr;
  ListNode* ptr;
  while (head) {
    ptr = head;
    head = head->next;
    ptr->next = newHead;
    newHead = ptr;
  }
  return newHead;
}

ListNode* swapPairs(ListNode* head) {
  ListNode* first = nullptr;
  ListNode* second = nullptr;
  while (head) {
    if (head) {
      ListNode* ptr = head;
      head = head->next;
      ptr->next = first;
      first = ptr;
    }
    if (head) {
      ListNode* ptr = head;
      head = head->next;
      ptr->next = second;
      second = ptr;
    }
  }
  first = reverse(first);
  second = reverse(second);

  // 先从second开始拼接
  ListNode* newHead = nullptr;
  ListNode* ptr;
  while (first && second) {
    if (second) {
      ptr = second;
      second = second->next;
      ptr->next = newHead;
      newHead = ptr;
    }
    if (first) {
      ptr = first;
      first = first->next;
      ptr->next = newHead;
      newHead = ptr;
    }
  }
  if (first) {
    first->next = newHead;
    newHead = first;
  }
  if (second) {
    second->next = newHead;
    newHead = second;
  }

  // traverse(first);
  // traverse(second);
  // traverse(newHead);
  return reverse(newHead);
}

ListNode* reverse1(ListNode* list) {
  if (list == nullptr || list->next == nullptr) return list;
  ListNode* rev = nullptr;
  ListNode* p = list;
  ListNode* ptr;
  while (p) {
    ptr = p;
    p = p->next;
    ptr->next = rev;
    rev = ptr;
  }
  return rev;
}

ListNode* tail(ListNode* list) {
  ListNode* ptr = list;
  while (ptr && ptr->next) {
    ptr = ptr->next;
  }
  return ptr;
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
  if (head == nullptr || head->next == nullptr) return head;
  if (left == right) return head;

  ListNode* dummy = new ListNode(0, head);

  vector<ListNode*> vec;

  vec.push_back(dummy);

  ListNode* ptr = dummy;
  while (ptr && ptr->next) {
    if (ptr->next->val == left) {
      vec.push_back(ptr->next);
      ptr->next = nullptr;
    }
    if (ptr->val == right) {
      vec.push_back(ptr->next);
      ptr->next = nullptr;
    }
    ptr = ptr->next;
  }
  auto rev = reverse1(vec[1]);
  ListNode* tail1 = tail(dummy);
  tail1->next = rev;
  ListNode* tail2 = tail(rev);
  tail2->next = vec[2];
  return dummy->next;
}

}  // namespace leetcode
