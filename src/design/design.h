#ifndef __DESIGN_H_
#define __DESIGN_H_

#include <algorithm>
#include <climits>
#include <cstdarg>
#include <cstddef>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

namespace design {

class CQueue {
 private:
  stack<int> first;
  stack<int> second;

 public:
  CQueue() {}

  void appendTail(int value) { first.push(value); }

  int deleteHead() {
    if (first.empty() && second.empty()) return -1;
    if (!second.empty()) {
      int val = second.top();
      second.pop();
      return val;
    } else {
      while (!first.empty()) {
        second.push(first.top());
        first.pop();
      }
      int val = second.top();
      second.pop();
      return val;
    }
  }
};

class MinStack {
 private:
  std::stack<int> stackA;
  std::stack<int> stackB;

 public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    stackA.push(x);
    if (stackB.empty() || x <= stackB.top()) stackB.push(x);
  }

  void pop() {
    int top = stackA.top();
    stackA.pop();
    if (top == stackB.top()) stackB.pop();
  }

  int top() { return stackA.top(); }

  int min() { return stackB.top(); }
};

/////////////////////////

// struct Node {
//   Node* next_{nullptr};
//   Node* prev_{nullptr};
//   int key_;
//   int value_;
//   Node(int key, int value) : key_(key), value_(value) {}
// };

// Node* InsertTail(Node* list, Node* node) {
//   if (list == nullptr) return node;
//   Node* tail = list->prev_;
//   tail->next_ = node;
//   node->prev_ = tail;
//   node->next_ = list;
//   list->prev_ = node;
//   return list;
// }
// Node* RemoveHead(Node* list) {
//   if (list == nullptr) return nullptr;
//   if (list->next_ == list) {
//     delete list;
//     return nullptr;
//   }
//   Node* head = list;
//   list = list->next_;

//   Node* prev = head->prev_;
//   delete head;

//   list->prev_ = prev;
//   prev->next_ = list;
//   return list;
// }

// Node* RemoveNode(Node* list, int key) {
//   if (list == nullptr) return nullptr;
//   if (list->key_ == key) {
//     return RemoveHead(list);
//   }
//   Node* ptr = list->next_;
//   while (ptr != list) {
//     if (ptr->key_ == key) {
//       Node* prev = ptr->prev_;
//       Node* next = ptr->next_;
//       prev->next_ = next;
//       next->prev_ = prev;
//       break;
//     }
//     ptr = ptr->next_;
//   }
//   return list;
// }

// Node* RemoveNode(Node* list, Node* node) {
//   if (list == nullptr) return nullptr;
//   if (list->key_ == node->key_) {
//     return RemoveHead(list);
//   }
//   Node* ptr = list->next_;
//   while (ptr != list) {
//     if (ptr->key_ == node->key_) {
//       Node* prev = ptr->prev_;
//       Node* next = ptr->next_;
//       prev->next_ = next;
//       next->prev_ = prev;
//       break;
//     }
//     ptr = ptr->next_;
//   }
//   return list;
// }

// Node* NewNode(int key, int value) {
//   Node* node = new Node(key, value);
//   node->next_ = node;
//   node->prev_ = node;
//   return node;
// }

// void TraverseNode(Node* list) {
//   if (list == nullptr) return;
//   Node* ptr = list;
//   do {
//     std::cout << ptr->key_ << ", v = " << ptr->value_ << std::endl;
//     ptr = ptr->next_;
//   } while (ptr != list);
//   std::cout << "---" << std::endl;
// }

// class LRUCache {
//  private:
//   Node* list_;
//   map<int, Node*> key_map_;
//   int capacity_;
//   int size_;

//  public:
//   LRUCache(int capacity) {
//     list_ = nullptr;
//     capacity_ = capacity;
//     size_ = 0;
//   }

//   int get(int key) {
//     if (size_ < 0 || key_map_.find(key) == key_map_.end()) {
//       return -1;
//     }
//     auto ptr = key_map_.find(key)->second;
//     int value = ptr->value_;

//     list_ = RemoveNode(list_, ptr);
//     ptr = NewNode(key, value);
//     list_ = InsertTail(list_, ptr);
//     key_map_[key] = ptr;
//     return value;
//   }

//   void put(int key, int value) {
//     // 如果已经存在
//     if (get(key) >= 0) {
//       Node* ptr = list_->prev_;
//       ptr->value_ = value;
//       return;
//     }
//     // 如果满了
//     if (size_ == capacity_) {
//       cout << "满了" << endl;
//       key_map_.erase(list_->key_);
//       list_ = RemoveHead(list_);
//       auto ptr = NewNode(key, value);
//       list_ = InsertTail(list_, ptr);
//       key_map_[key] = ptr;
//       return;
//     }

//     // 其他情况
//     auto ptr = NewNode(key, value);
//     list_ = InsertTail(list_, ptr);
//     key_map_[key] = ptr;
//     size_++;
//   }
// };

struct ListNode {
  int key_;
  int value_;
  ListNode* next_{nullptr};
  ListNode* prev_{nullptr};
  ListNode(int key, int value) : key_(key), value_(value) {}
};

ListNode* NewListNode(int key, int value) {
  ListNode* node = new ListNode(key, value);
  node->next_ = node;
  node->prev_ = node;
  return node;
}
ListNode* InsertTail(ListNode* list, ListNode* node) {
  if (list == nullptr) return node;

  ListNode* prev = list->prev_;

  prev->next_ = node;
  node->prev_ = prev;

  node->next_ = list;
  list->prev_ = node;
  return list;
}

ListNode* RemoveHead(ListNode* list) {
  if (list == nullptr) return nullptr;
  if (list->next_ == list) {
    delete list;
    return nullptr;
  }
  ListNode* next = list->next_;
  ListNode* prev = list->prev_;

  next->prev_ = prev;
  prev->next_ = next;

  list = next;
  return list;
}

ListNode* RemoveNode(ListNode* list, ListNode* node) {
  if (list == nullptr) return nullptr;
  if (list->key_ == node->key_) {
    return RemoveHead(list);
  }
  ListNode* ptr = list;
  do {
    if (ptr->key_ == node->key_) {
      ptr = RemoveHead(ptr);
      return list;
    }
    ptr = ptr->next_;
  } while (ptr != list);
  return nullptr;
}

void TraverseNode(ListNode* list) {
  if (list == nullptr) return;
  ListNode* ptr = list;
  do {
    cout << ptr->key_ << ", " << ptr->value_ << endl;
    ptr = ptr->next_;
  } while (ptr != list);
  cout << "--" << endl;
}

class LRUCache {
  ListNode* LRUList_;
  map<int, ListNode*> key_map_;
  int capacity_;
  int size_;

 public:
  LRUCache(int capacity) {
    LRUList_ = nullptr;
    capacity_ = capacity;
    size_ = 0;
  }

  int get(int key) {
    if (size_ <= 0 || key_map_.find(key) == key_map_.end()) return -1;
    ListNode* ptr = key_map_[key];
    int value = ptr->value_;
    LRUList_ = RemoveNode(LRUList_, ptr);
    LRUList_ = InsertTail(LRUList_, NewListNode(key, value));
    TraverseNode(LRUList_);
    return value;
  }

  void put(int key, int value) {
    if (get(key) >= 0) {
      ListNode* tail = LRUList_->prev_;
      tail->value_ = value;
      TraverseNode(LRUList_);
      return;
    }

    if (size_ == capacity_) {
      LRUList_ = RemoveHead(LRUList_);
      LRUList_ = InsertTail(LRUList_, NewListNode(key, value));
      TraverseNode(LRUList_);
      return;
    }
    LRUList_ = InsertTail(LRUList_, NewListNode(key, value));
    TraverseNode(LRUList_);
    size_++;
  }
};

class MedianFinder {
 private:
  std::priority_queue<int, vector<int>, std::less<int>> left_;
  std::priority_queue<int, vector<int>, std::greater<int>> right_;

 public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    if (left_.size() == right_.size()) {
      if (right_.empty()) left_.push(num);
      // 左边应该多一个元素
      if (!right_.empty() && num <= right_.top())
        left_.push(num);
      else if (!right_.empty() && num > right_.top()) {
        left_.push(right_.top());
        right_.pop();
        right_.push(num);
      }
    } else if (left_.size() > right_.size()) {
      // 右边应该多一个元素
      if (num >= left_.top())
        right_.push(num);
      else if (num < left_.top()) {
        right_.push(left_.top());
        left_.pop();
        left_.push(num);
      }
    }
  }

  double findMedian() {
    if (left_.size() == right_.size()) {
      return (left_.top() + right_.top()) * 1.0 / 2;
    } else {
      return left_.top();
    }
  }
};

// class Solution {
//  public:
//   int singleNumber(vector<int>& nums) {
//     vector<int> bitcount(32, 0);
//     for (auto num : nums) {
//       for (int i = 0; i < 32; i++) {
//         if (num & 1 << i) bitcount[i]++;
//       }
//     }
//     int unique_number = 0;
//     for (int i = 0; i < 32; i++) bitcount[i] %= 3;
//     for (int i = 0; i < 32; i++) {
//       unique_number += i << 1;
//     }
//     return unique_number;
//   }
// };

// class Solution {
//  public:
//   int majorityElement(vector<int>& nums) {
//     unordered_map<int, int> umap;
//     for (auto num : nums) {
//       umap[num]++;
//     }
//     for (auto item : umap) {
//       if (item.second > nums.size() / 2) {
//         return item.first;
//       }
//     }
//     return -1;
//   }
// };

// class MaxQueue {
//   queue<int> queue_;
//   deque<int> max_queue_;

//  public:
//   MaxQueue() {}

//   int max_value() {
//     if (queue_.empty()) return -1;
//     return max_queue_.front();
//   }

//   void push_back(int value) {
//     queue_.push(value);
//     while (!max_queue_.empty() && max_queue_.back() < value) {
//       max_queue_.pop_back();
//     }
//     max_queue_.push_back(value);
//   }

//   int pop_front() {
//     if (queue_.empty()) return -1;
//     int value = queue_.front();
//     queue_.pop();
//     if (value == max_queue_.front()) {
//       max_queue_.pop_front();
//     }
//     return value;
//   }
// };

class RingQueue {
 private:
  vector<int> list_;
  int size_;
  int head_;
  int tail_;
  int capacity_;

 public:
  RingQueue(int capacity) {
    capacity_ = capacity;
    head_ = 0;
    tail_ = 0;
    size_ = 0;
  }

  bool Insert(int value) {
    if (size_ == capacity_) return false;
    list_[tail_] = value;
    tail_ = (tail_ + 1) % capacity_;
    size_++;
    cout << "tail = " << tail_ << endl;
    return true;
  }

  void Pop() {
    if (size_ == 0) return;
    head_ = (head_ + 1) % capacity_;
    size_--;
  }

  bool Empty() { return size_ == 0; }

  int Size() { return size_; }

  int front() {
    if (!Empty()) return list_[head_];
    return -1;
  }
};

}  // namespace design

#endif