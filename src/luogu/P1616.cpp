// https://www.luogu.com.cn/problem/P1616
//  完全背包问题
#include <algorithm>
#include <iostream>
using namespace std;

long long weight[10010];
long long value[10010];
long long dp[10000010];

int main() {
  //
  long long bagWeight;
  int n;
  cin >> bagWeight >> n;

  for (int i = 0; i < n; i++) {
    cin >> weight[i] >> value[i];
  }

  // 完全背包，每种元素数量不限
  for (int i = 0; i < n; i++) {
    for (int j = weight[i]; j <= bagWeight; j++) {
      dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
  }

  cout << dp[bagWeight] << endl;
  //
  //
  return 0;
}
