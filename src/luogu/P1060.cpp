#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

long long dp[30001];
long long weight[25];
long long value[25];

int main() {
  int bagWeight, n;
  cin >> bagWeight >> n;

  for (int i = 0; i < n; i++) {
    cin >> weight[i] >> value[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = bagWeight; j >= weight[i]; j--) {
      dp[j] = max(dp[j], dp[j - weight[i]] + weight[i] * value[i]);
    }
  }

  cout << dp[bagWeight] << endl;

  //
  return 0;
}