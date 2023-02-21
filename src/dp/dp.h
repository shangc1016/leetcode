#ifndef __DP_H_
#define __DP_H_

#include <vector>

using namespace std;

namespace leetcode {

int fib(int n);

int climbStairs(int n);

int minCostClimbingStairs(vector<int>& cost);

int uniquePaths(int m, int n);

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
}  // namespace leetcode
#endif