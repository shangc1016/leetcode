// 连通度 连通分量

#include <cstring>
#include <iostream>
#include <unordered_set>

using namespace std;

int fa[1010];

int find(int x) {
  if (fa[x] != x) return find(fa[x]);
  return fa[x];
}

int main() {
  int n, m;
  while (true) {
    cin >> n;
    if (n == 0) break;
    cin >> m;

    unordered_set<int> uset;
    for (int i = 1; i <= n; i++) fa[i] = i;
    int x, y;
    for (int i = 1; i <= m; i++) {
      cin >> x >> y;
      fa[find(x)] = find(y);
    }

    for (int i = 1; i <= n; i++) {
      uset.insert(find(i));
    }
    cout << uset.size() - 1 << endl;
  }
  //
  return 0;
}