// https://www.luogu.com.cn/problem/P1048
// 01背包问题

#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;

int weight[101];
int value[101];

int dp[1001];

int main() {
  //

  int bagWeight, n;

  cin >> bagWeight >> n;
  for (int i = 0; i < n; i++) {
    cin >> weight[i] >> value[i];
  }

  // dp问题，dp[i]表示容量为i的背包可以装的物品的最大价值。
  // 先遍历物品，再遍历背包
  //   背包逆序遍历
  int result = 0;
  for (int i = 0; i < n; i++) {
    for (int j = bagWeight; j >= weight[i]; j--) {
      dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
  }

  cout << dp[bagWeight] << endl;

  //
  return 0;
}