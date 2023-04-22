// 并查集 路径压缩

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int fa[100050];

int find(int x) {
  if (fa[x] != x) {
    fa[x] = find(fa[x]);
  }
  return fa[x];
}

int main() {
  //
  int n, m, p;
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }

  int x, y;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    fa[find(x)] = find(y);
  }

  for (int i = 1; i <= p; i++) {
    scanf("%d%d", &x, &y);
    if (find(x) == find(y)) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }

  return 0;
}