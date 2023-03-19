#ifndef __GRAPH_H_
#define __GRAPH_H_

#include <map>
#include <queue>
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

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (node == nullptr) return nullptr;
    map<int, bool> nodemap;

    Node* newNode = new Node(node->val);
    queue<Node*> old_;
    queue<Node*> new_;

    old_.push(node);
    new_.push(newNode);
    while (!old_.empty()) {
      auto old_ptr = old_.front();
      auto new_ptr = new_.front();
      old_.pop();
      new_.pop();

      if (nodemap[old_ptr->val] == true) continue;

      nodemap[old_ptr->val] = true;

      for (auto neighbor : old_ptr->neighbors) {
        if (nodemap.find(neighbor->val) == nodemap.end()) {
          old_.push(neighbor);
          new_.push(new Node(neighbor->val));
          nodemap[neighbor->val] = true;
        }
      }
    }
    return newNode;
  }
};
}  // namespace graph

#endif