#include <iostream>
#include <vector>

using namespace std;

// 01背包问题
int main() {
  int N, V;
  vector<int> weights;
  vector<int> values;
  cin >> N >> V;
  for (int i = 0; i < N; i++) {
    int value, weight;
    cin >> weight >> value;

    weights.push_back(weight);
    values.push_back(value);
  }

  // dp问题，dp[i]表示容量为i的背包，可以获得的最大价值
  vector<int> dp(N, 0);

  for (int i = 0; i < N; i++) {
    for (int j = V; j >= weights[i]; j--) {
      dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
    }
  }
  return dp[N];
}