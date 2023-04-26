#include <bits/stdc++.h>

#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

long long a[10001];

int main() {
  int n, t;
  unordered_set<int> uset;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    uset.insert(t);
  }

  int longest = 0;
  for (int i = 0; i < n; i++) {
    int v = a[i];
    if (uset.find(v - 1) != uset.end()) {
      continue;
    }

    int len = 0;
    while (uset.find(v) != uset.end()) {
      v++;
      len++;
      cout << "v++" << endl;
    }
    cout << i << "," << len << endl;
    longest = max(longest, len);
  }
  cout << longest << endl;

  //
  return 0;
}