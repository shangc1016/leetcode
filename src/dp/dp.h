#ifndef __DP_H_
#define __DP_H_

#include <vector>
#include <algorithm>

using namespace std;

namespace leetcode {

int fib(int n);

int climbStairs(int n);

int minCostClimbingStairs(vector<int>& cost);

int uniquePaths(int m, int n);

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);

int integerBreak(int n);

int numTrees(int n) ;
}  // namespace leetcode
#endif