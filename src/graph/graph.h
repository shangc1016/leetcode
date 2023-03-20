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

}  // namespace graph

#endif