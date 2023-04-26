#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

int weight[31];
int dp[20001];

int main() {
  int bagWeight, n;
  cin >> bagWeight >> n;
  for (int i = 0; i < n; i++) {
    cin >> weight[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = bagWeight; j >= weight[i]; j--) {
      dp[j] = max(dp[j], dp[j - weight[i]] + weight[i]);
    }
  }

  cout << bagWeight - dp[bagWeight] << endl;
  //
  return 0;
}