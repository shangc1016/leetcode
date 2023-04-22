#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <vector>

#include "array/array.h"

using namespace std;

int a[100];
int d[201];

// 构建线段树
void build(int s, int t, int p) {
  // [s, t] 为区间，p为当前节点编号
  // 如果线段起点、终点相同，停止条件
  if (s == t) {
    d[p] = a[s];
    return;
  }
  int m = (s + t) / 2;
  build(s, m, 2 * p);
  build(m + 1, t, 2 * p + 1);
  d[p] = d[2 * p] + d[2 * p + 1];
}

// 区间求和
int getsum(int l, int r, int s, int t, int p) {
  // [l, r]是所求的区间范围
  // [s, t]是当前节点p所包含的区间范围
  // p是当前节点的编号

  if (l <= s && t <= r) {
    return d[p];
  }
  int m = (s + t) / 2;
  int sum = 0;
  if (l <= m) sum += getsum(l, r, s, m, 2 * p);
  if (r > m) sum += getsum(l, r, m + 1, t, 2 * p + 1);

  return sum;
}

int main() {
  //
  //

  a[0] = 10;
  a[1] = 11;
  a[2] = 12;
  a[3] = 13;
  a[4] = 14;

  

  build(0, 4, 1);

  for (int i = 1; i < 5 * 2 + 1; i++) {
    cout << d[i] << endl;
  }

  cout << endl;

  cout << getsum(0, 2, 0, 4, 1) << endl;

  return 0;
}
