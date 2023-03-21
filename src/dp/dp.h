#ifndef __DP_H_
#define __DP_H_

#include <algorithm>
#include <string>
#include <vector>

#include "../binarytree/binarytree.h"

using namespace binarytree;
using namespace std;

namespace dp {
int fib(int n);

int climbStairs(int n);

int minCostClimbingStairs(vector<int>& cost);

int uniquePaths(int m, int n);

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);

int integerBreak(int n);

int numTrees(int n);

bool canPartition(vector<int>& nums);

int lastStoneWeightII(vector<int>& stones);

int findTargetSumWays(vector<int>& nums, int target);

int findMaxForm(vector<string>& strs, int m, int n);

int change(int amount, vector<int>& coins);

int combinationSum4(vector<int>& nums, int target);

int climbStairsII(int n, int maxStep);

int coinChange(vector<int>& coins, int amount);

int numSquares(int n);

bool wordBreak(string s, vector<string>& wordDict);

int maxProfit(vector<int>& prices);

vector<int> countBits(int n);

int translateNum(int num);

int lengthOfLongestSubstring(string s);

int cuttingRope(int n);

int rob(vector<int>& nums);

int rob(TreeNode* root);

int maxProfit(vector<int>& prices);

int lengthOfLIS(vector<int>& nums);

int maxProduct(vector<int>& nums);

int findLengthOfLCIS(vector<int>& nums);

int findLength(vector<int>& nums1, vector<int>& nums2);

int longestCommonSubsequence(string text1, string text2);

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2);

int maxSubArray(vector<int>& nums);

bool isSubsequence(string s, string t);

int numDistinct(string s, string t);
}  // namespace dp
#endif