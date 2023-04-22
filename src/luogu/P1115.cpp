
#include <algorithm>
#include <cstdint>
#include <iostream>
using namespace std;

int arr[200001];
int dp[200001];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int result{INT32_MIN};

  dp[0] = arr[0];
  for (int i = 1; i < n; i++) {
    if (dp[i - 1] < 0 && arr[i] < 0) {
      dp[i] = max(dp[i - 1], arr[i]);
    } else {
      dp[i] = dp[i - 1] < 0 ? arr[i] : dp[i - 1] + arr[i];
    }
    result = max(result, dp[i]);
  }
  cout << result << endl;
  return 0;
}