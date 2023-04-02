#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <map>
#include <ostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

int main() {
  //
  //
  std::list<int> list_;

  map<int, int> umap;

  umap.insert({1, 1});
  umap.insert({2, 1});
  umap.insert({5, 1});

  for (auto it : umap) {
    cout << it.first << ", "<< it.second << std::endl;
  }

  //
  return 0;
}