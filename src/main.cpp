#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

#include "array/array.h"
#include "binarytree/binarytree.h"
#include "hash/hash.h"
#include "list/list.h"
#include "string/istring.h"

using namespace std;
using namespace leetcode;

int main(int argc, char** argv) {
  string str = "lrloseumgh";
  cout << reverseLeftWords(str, 6) << endl;
  return 0;
}
