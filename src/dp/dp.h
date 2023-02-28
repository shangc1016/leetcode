#ifndef __DP_H_
#define __DP_H_

#include <algorithm>
#include <vector>

using namespace std;

namespace leetcode {

int fib(int n);

int climbStairs(int n);

int minCostClimbingStairs(vector<int>& cost);

int uniquePaths(int m, int n);

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);

int integerBreak(int n);

int numTrees(int n);

bool canPartition(vector<int>& nums);

int lastStoneWeightII(vector<int>& stones);
}  // namespace leetcode
#endif