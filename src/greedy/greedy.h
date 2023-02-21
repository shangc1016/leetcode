#ifndef __GREEDY_H_
#define __GREEDY_H_

#include <string>
#include <vector>

using namespace std;

namespace leetcode {
int findContentChildren(vector<int>& g, vector<int>& s);

int wiggleMaxLength(vector<int>& nums);

int maxSubArray(vector<int>& nums);

int maxProfit(vector<int>& prices);

bool canJump(vector<int>& nums);

int jump(vector<int>& nums);

int largestSumAfterKNegations(vector<int>& nums, int k);
}  // namespace leetcode

#endif