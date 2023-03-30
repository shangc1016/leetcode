#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
char matrix[101][101];

int helper(int x, int y) {}

int main() {
  //
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> matrix[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (matrix[i][j] == '*') continue;
      matrix[i][j] = helper(i, j) + '0';
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
  //
}