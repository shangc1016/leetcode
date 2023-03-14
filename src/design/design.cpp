#include "design.h"

#include <cstddef>

namespace design {

Node* InsertTail(Node* list, Node* node) {
  if (list == nullptr) return node;
  Node* tail = list->prev_;
  tail->next_ = node;
  node->prev_ = tail;
  node->next_ = list;
  list->prev_ = node;
  return list;
}

Node* RemoveHead(Node* list) {
  if (list == nullptr) return nullptr;
  if (list->next_ == list) {
    delete list;
    return nullptr;
  }
  Node* head = list;
  list = list->next_;

  Node* prev = head->prev_;
  delete head;

  list->prev_ = prev;
  prev->next_ = list;
  return list;
}

Node* RemoveNode(Node* list, int key) {
  if (list == nullptr) return nullptr;
  if (list->next_ == list && list->key_ == key) {
    delete list;
    return nullptr;
  }
  if (list->next_ == list) {
    return list;
  }
  if (list->key_ == key) {
    list = RemoveHead(list);
    return list;
  }
  Node* ptr = list;

  do {
    if (ptr->key_ == key) {
      ptr = RemoveHead(ptr);
    }
    ptr = ptr->next_;
  } while (ptr != list);
  return list;
}
}  // namespace design