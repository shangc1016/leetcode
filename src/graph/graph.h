#ifndef __GRAPH_H_
#define __GRAPH_H_

#include <list>
#include <map>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

namespace graph {

class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

// 实现前缀树
class Trie {
 private:
  struct TrieNode {
    char ch_;
    bool is_end_;
    TrieNode* children_[26]{nullptr};
    TrieNode(char ch) : ch_(ch) {}
  };

  TrieNode* root;

 public:
  Trie() { root = new TrieNode('\0'); }

  void insert(string word) {
    TrieNode* ptr = root;
    for (auto ch : word) {
      if (ptr->children_[ch - 'a'] == nullptr) {
        ptr->children_[ch - 'a'] = new TrieNode(ch - 'a');
      }
      ptr = ptr->children_[ch - 'a'];
    }
    ptr->is_end_ = true;
  }

  bool search(string word) {
    TrieNode* ptr = root;
    for (auto ch : word) {
      if (ptr->children_[ch - 'a'] == nullptr) {
        return false;
      }
      ptr = ptr->children_[ch - 'a'];
    }
    if (ptr->is_end_ == true) return true;
    return false;
  }

  bool startsWith(string prefix) {
    TrieNode* ptr = root;
    for (auto ch : prefix) {
      if (ptr->children_[ch - 'a'] == nullptr) return false;
      ptr = ptr->children_[ch - 'a'];
    }
    for (auto child : ptr->children_) {
      if (child != nullptr) return true;
    }
    return false;
  }
};

}  // namespace graph

#endif