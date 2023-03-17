#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <ostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

#include "array/array.h"
#include "backtracing/backtracing.h"
#include "binarytree/binarytree.h"
#include "bipointer/bipointer.h"
#include "design/design.h"
#include "dp/dp.h"
#include "hash/hash.h"
#include "list/list.h"
#include "slidewindow/slidewindow.h"
#include "stack/stack.h"
#include "string/string.h"
#include "tree/tree.h"

using namespace std;
// using namespace leetcode;

using namespace design;

using namespace bipointer;

using namespace binarytree;

int main(int argc, char** argv) {
  Codec codec;
  auto tree = codec.deserialize("-1,0,1*0,-1,1");

  auto vec = codec.str2vec("1,-1,2,3,-234");
  cout << endl;
  for (auto item : vec) cout << item << endl;
  delete tree;
}
