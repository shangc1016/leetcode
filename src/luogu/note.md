

### 打印幻方

```cpp
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {

  int N;
  cin >> N;

  vector<vector<int>> matrix(40, vector<int>(40, 0));

  matrix[1][N / 2 + 1] = 1;

  int lastX = 1;
  int lastY = N / 2 + 1;

  for (int i = 2; i <= N * N; i++) {
    if (lastX == 1 && lastY != N) {
      matrix[N][lastY + 1] = i;
      lastX = N;
      lastY = lastY + 1;
    } else if (lastY == N && lastX != 1) {
      matrix[lastX - 1][1] = i;
      lastX = lastX - 1;
      lastY = 1;
    } else if (lastX == 1 && lastY == N) {
      matrix[lastX + 1][lastY] = i;
      lastX = lastX + 1;
    } else if (lastX != 1 && lastY != N) {
      if (matrix[lastX - 1][lastY + 1] == 0) {
        matrix[lastX - 1][lastY + 1] = i;
        lastX = lastX - 1;
        lastY = lastY + 1;
      } else {
        matrix[lastX + 1][lastY] = i;
        lastX = lastX + 1;
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}

```