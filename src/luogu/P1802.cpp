// https://www.luogu.com.cn/problem/P1802
// 01背包
#include <algorithm>
#include <iostream>
#include <locale>
using namespace std;

long long weight[1001];
long long lose[1001];
long long win[1001];

long long dp[1001];

int main() {
  //
  int n, bagWeight;
  cin >> n >> bagWeight;
  for (int i = 0; i < n; i++) {
    cin >> lose[i] >> win[i] >> weight[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = bagWeight; j >= 0; j--) {
      if (dp[j - weight[i]] + win[i] > dp[j] + lose[i]) {
        dp[j] = dp[j - weight[i]] + win[i];
      } else {
        dp[j] = dp[j] + lose[i];
      }
    }
  }

  cout << dp[bagWeight] * 5 << endl;
  //
  return 0;
}