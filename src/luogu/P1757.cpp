#include <bits/stdc++.h>

#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

long long weight[1001];
long long value[1001];
long long group[1001];
long long dp[1001];

// 分组dp
//
// 

int main() {
  //
  int bagWeight, n;
  cin >> bagWeight >> n;

  for (int i = 0; i < n; i++) {
    cin >> weight[i] >> value[i] >> group[i];
  }

  unordered_map<int, int> umap;

  for (int i = 0; i < n; i++) {
    for (int j = bagWeight; j >= weight[i]; j--) {
      if (umap.find(group[i]) != umap.end()) {
        int index = umap.find(group[i])->second;
        if (dp[j - weight[i]] + value[i] > dp[j] &&
            dp[j - weight[i]] + value[i] >
                dp[j - weight[index]] + value[index]) {
          dp[j] = dp[j - weight[i]] + value[i];
          //   umap.erase(group[i]);
          umap.insert({group[i], i});
        }
      } else {
        if (dp[j - weight[i]] + value[i] > dp[j]) {
          dp[j] = dp[j - weight[i]] + value[i];
          umap.insert({group[i], i});
        }
      }
    }
  }

  cout << dp[bagWeight] << endl;

  return 0;
}