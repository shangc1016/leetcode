#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <list>
#include <locale>
#include <map>
#include <ostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Compare {
 public:
  bool operator()(int A, int B) { return A < B; }
};
int main() {
  //
  //
  //

  for (int i = 0; i < 100000; i++) {
    auto t1 = std::chrono::high_resolution_clock::now();
    uint64_t val = t1.time_since_epoch().count();
    printf("%ld\n", val);
  }

 


  return 0;
}