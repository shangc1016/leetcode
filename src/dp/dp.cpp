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

// int uniquePaths(int m, int n) {
//   vector<vector<int>> grid(m, vector<int>(n, 0));
//   for (int i = 0; i < m; i++) grid[i][0] = i;
//   for (int i = 0; i < n; i++) grid[0][i] = i;
//   for (int i = 1; i < m; i++) {
//     for (int j = 1; j < n; j++) {
//       grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
//     }
//   }
//   return grid[m - 1][n - 1];
// }

// int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//   int m = obstacleGrid.size();
//   int n = obstacleGrid[0].size();
//   if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
//   vector<vector<int>> dp(m, vector<int>(n, 0));
//   for (int i = 0; i < m && obstacleGrid[i][0] != 1; i++) dp[i][0] = 1;
//   for (int i = 0; i < n && obstacleGrid[0][i] != 1; i++) dp[0][i] = 1;
//   for (int i = 1; i < m; i++) {
//     for (int j = 1; j < n; j++) {
//       if (obstacleGrid[i][j] == 1) continue;
//       dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//     }
//   }
//   return dp[m - 1][n - 1];
// }

// 整数分拆 https://leetcode.cn/problems/integer-break/
// dp[i]表示拆分整数i得到的乘积最大值
// 整数i分解为整数j和i-j
// 或者递归的表示为dp[i-j] * j，此时递归的分解i-j
// dp[i] = max(j * (i-j), dp[i-j] * j)
// int integerBreak(int n) {
//   vector<int> dp(n + 1, 0);
//   dp[2] = 1;
//   for (int i = 3; i <= n; i++) {
//     for (int j = 1; j < i; j++) {
//       dp[i] = max({dp[i - j] * j, (i - j) * j, dp[i]});
//     }
//   }
//   return dp[n];
// }

// 不同的二叉搜索树 https://leetcode.cn/problems/unique-binary-search-trees/
// int numTrees(int n) {
//   //
//   vector<int> dp(n + 1, 0);
//   dp[0] = 1;
//   dp[1] = 1;
//   for (int i = 2; i <= n; i++) {
//     for (int j = 0; j < i; j++) {
//       dp[i] = dp[j] * dp[i - j];
//     }
//   }
//   return dp[n];
// }

int uniquePaths(int m, int n) {
  vector<vector<int>> dp(m, vector<int>(n, 0));
  for (int i = 0; i < m; i++) dp[i][0] = 1;
  for (int i = 0; i < n; i++) dp[0][i] = 1;
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }
  return dp[m - 1][n - 1];
}

// 障碍可能存在三种地方
// 1：开始位置、终点位置
// 2：最上面一行，最左边一列
// 3：内部

// dp[i][j]记录的是到达(i, j)位置的不同走法
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  //
  int height = obstacleGrid.size();
  int width = obstacleGrid[0].size();
  // 起点、终点有障碍：直接返回0，走不到终点
  if (obstacleGrid[height - 1][width - 1] || obstacleGrid[0][0]) return 0;
  vector<vector<int>> dp(height, vector<int>(width, 0));
  // 最上面一行、最左边一列有障碍：自障碍后面都走不到
  for (int i = 0; i < height && obstacleGrid[i][0] != 1; i++) dp[i][0] = 1;
  for (int i = 0; i < width && obstacleGrid[0][i] != 1; i++) dp[0][i] = 1;

  for (int i = 1; i < height; i++) {
    for (int j = 1; j < width; j++) {
      // 内部有障碍
      if (obstacleGrid[i][j]) continue;
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }
  return dp[height - 1][width - 1];
}

int integerBreak(int n) {
  vector<int> dp(n + 1, 0);
  dp[2] = 1;
  for (int i = 3; i <= n; i++) {
    for (int j = 1; j < i / 2; j++) {
      dp[i] = max({dp[i], dp[i - j] * j, (i - j) * j});
    }
  }
  return dp[n];
}

// 递归问题，
// dp[i]表示n为i的时候的二叉树个数
// dp[1] = 1;
// dp[2] = 2;
// p[n], 根节点占一个，左右子节点的和为n-1，关键在于左右子树怎么分这n-1个节点
// 分发分别为(0, n-1),...(n-1, 0)
// n-1个节点构成的子树个数，继续往下递归...
int numTrees(int n) {
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 3; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      dp[i] += dp[j] * dp[i - j - 1];
    }
  }
  return dp[n];
}

// https://leetcode.cn/problems/partition-equal-subset-sum/
bool canPartition(vector<int>& nums) {
  // 背包问题，dp[i]表示背包容量为i的时候的最大价值
  // 在这个问题中，weight[i] = values[i] = nums[i];
  // dp[i] = max({dp[i], dp[i - weight[j]] + values[j]});
  // 题目中nums.length最大200，nums[i]最大100
  // 那么数组的和最大20000，只需要计算难呢过不能平分，也就是只需要10000
  // 所以开辟dp[10001];

  int sum = 0;
  for (auto item : nums) sum += item;

  if (sum % 2 != 0) return false;
  sum /= 2;

  vector<int> dp(10001, 0);
  for (int i = 0; i < nums.size(); i++) {
    for (int j = sum; j >= nums[i]; j--) {
      dp[j] = max({dp[j], dp[j - nums[i]] + nums[i]});
    }
  }
  return dp[sum] == sum;
}

// 背包问题，
// dp[i] 表示容量为i的背包，最多可以背的最大重量是dp[i]
// dp[i] = max({dp[i], dp[i - weight[j]] + weight[j]})
// 石头个数最大30，重量最大100。所以容量最大为30000
// 这个问题只需要尽可能的将石头按照重量平分，所以i最大是15001
int lastStoneWeightII(vector<int>& stones) {
  vector<int> dp(15001, 0);

  int sum = 0;
  for (auto item : stones) sum += item;
  int target = sum / 2;

  for (int i = 0; i < stones.size(); i++) {
    for (int j = target; j >= stones[i]; j--) {
      dp[j] = max({dp[j], dp[j - stones[i]] + stones[i]});
    }
  }
  return sum - dp[target] - dp[target];
}

}  // namespace leetcode