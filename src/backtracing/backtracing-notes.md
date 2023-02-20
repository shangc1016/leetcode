### 八皇后问题

还是回溯遍历的思路，一般的回溯针对与数组的排列组合问题。将其扩展到二位数组的排列组合问题，就是这个问题的解。  
二维棋盘中一行里的所有列是需要循环遍历的，查找合适的Q摆放位置。棋盘的行是在前一步的基础之上决定Q的摆放位置，所以行是作为递归方式遍历的。
```cpp
class Solution {
 private:
  vector<vector<string>> result;

  // n为棋盘大小，n*n
  // row是棋盘第几行
  void backtracing(int n, int row, vector<string> &chessboard) {
    // 到达棋盘最后一行，结束
    if (n == row) {
      result.push_back(chessboard);
      return;
    }

    // for循环遍历棋盘每一层的不同位置
    for (int col = 0; col < n; col++) {
        // 如果这个地方可以摆放Q的话，再摆放
      if (isValid(row, col, chessboard, n)) {
        chessboard[row][col] = 'Q';
        // 然后向下递归
        backtracing(n, row + 1, chessboard);
        // 最后恢复棋盘这一层的这个位置
        chessboard[row][col] = '.';
      }
    }
  }

  bool isValid(int row, int col, vector<string> &chessboard, int n) {
    // 检查同一列
    for (int i = 0; i < row; i++) {
      if (chessboard[i][col] == 'Q') return false;
    }
    // 检查45度是否有冲突↖
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
      if (chessboard[i][j] == 'Q') return false;
    }

    // 检查135度是否有冲突↗
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
      if (chessboard[i][j] == 'Q') return false;
    }

    return true;
  }

 public:
  vector<vector<string>> solveNQueens(int n) {
    result.clear();
    std::vector<string> chessboard(n, string(n, '.'));
    backtracing(n, 0, chessboard);
    return result;
  }
};
```