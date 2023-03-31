#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <map>
#include <ostream>
#include <vector>
using namespace std;

int arr[500001] = {0};
int dp[500001] = {0};

// 二分查找，加上线性探测

inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}

int main() {
  //

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    arr[i] = read();
  }

  // dp
  for (int i = 1; i < n; i++) {
    
   }

  //
  return 0;
}