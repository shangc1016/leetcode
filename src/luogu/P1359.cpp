#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

int m[201][201];
int dp[201];

int main() {
  //
  //
  int n;
  cin >> n;

  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cin >> m[i][j];
    }
    dp[i] = 1e9;
  }

  for (int i = n - 1; i >= 1; i--) {
    for (int j = i + 1; j <= n; j++) {
      dp[i] = min(dp[i], m[i][j] + dp[j]);
    }
  }

  cout << dp[1] << endl;
  //
  return 0;
}