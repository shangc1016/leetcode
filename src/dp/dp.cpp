#include "dp.h"

#include <vector>

namespace leetcode {

int fib(int n) {
  vector<int> dp(n + 2, 0);
  dp[0] = 0;
  dp[1] = 1;
  if (n <= 1) return dp[n];
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
}

int climbStairs(int n) {
  vector<int> dp(n + 2, 0);
  dp[1] = 1;
  dp[2] = 2;
  if (n <= 2) return dp[n];
  for (int i = 3; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
}

int minCostClimbingStairs(vector<int>& cost) {
  vector<int> dp(cost.size() + 1, 0);
  dp[0] = cost[0];
  dp[1] = cost[1];
  for (int i = 2; i < cost.size(); i++) {
    dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
  }
  return min(dp[cost.size() - 1], dp[cost.size() - 2]);
}

int uniquePaths(int m, int n) {
  vector<vector<int>> grid(m, vector<int>(n, 0));
  for (int i = 0; i < m; i++) grid[i][0] = i;
  for (int i = 0; i < n; i++) grid[0][i] = i;
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
    }
  }
  return grid[m - 1][n - 1];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  vector<vector<int>> grid(obstacleGrid.size(),
                           vector<int>(obstacleGrid[0].size(), 0));
  for (int i = 0; i < obstacleGrid.size(); i++) grid[i][0] = 1;
  for (int i = 0; i < obstacleGrid[0].size(); i++) grid[0][1] = 1;

  for (int i = 1; i < obstacleGrid.size(); i++) {
    for (int j = 1; j < obstacleGrid[0].size(); j++) {
      if (obstacleGrid[i][j] == 1) grid[i][j] = 0;
      else {
        int left = obstacleGrid[i][j - 1] == 1 ? 0 : grid[i][j - 1];
        int up = obstacleGrid[i - 1][j] == 1 ? 0 : grid[i - 1][j];
        grid[i][j] = left + up;
      }

    }
  }
  return grid[grid.size() - 1][grid[0].size() - 1];
}

}  // namespace leetcode