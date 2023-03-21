#include "dp.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace dp {

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

int findTargetSumWays(vector<int>& nums, int target) {
  // 背包问题，dp[j]表示装满容量为j的代码，可能的组合方式
  // 数组和为sum，因为数组元素可以随意加减组合，假设相加的和为A
  // 那么相减的和为sum - A 需要满足条件A - (sum - A) = target
  // 代入可得 A = A = (target + sum ) / 2
  // 如果结果有余数，说明A和(sum - A)相加不等于sum，直接返回
  // 如果abs(target) > sum，说明所有数组元素之和都不够target
  // (ps.这儿需要考虑target的绝对值，而sum不需要考虑绝对值。是因为题设规定
  // target可能为负数，而数组元素>=0)

  // 递推公式 dp[j] += dp[j - nums[i]];
  // 意思就是装满容量为j的背包，就是把容量为j-nums[i]的容量的背包的组合数量加起来
  // 从dp[j - nums[i]]到dp[j]只需要再添加一个nums[i]元素就可以了，这是一组合方式

  int sum = 0;
  int bagSize;

  for (auto item : nums) sum += item;

  if ((target + sum) % 2 != 0 || abs(target) > sum) return 0;

  bagSize = (target + sum) / 2;
  vector<int> dp(bagSize, 0);
  dp[0] = 1;

  for (int i = 0; i < nums.size(); i++) {
    for (int j = bagSize; j >= nums[i]; j--) {
      dp[j] += dp[j - nums[i]];
    }
  }
  return dp[bagSize];
}

int valueNums(string& str, char ch) {
  int count = 0;
  for (auto item : str)
    if (item == ch) count++;
  return count;
}

int findMaxForm(vector<string>& strs, int m, int n) {
  // m个0，n个1

  // dp问题，strs中的元素就是物品，每个物品只能取一次
  // m，n相当于一个背包，是两维的。属于01背包问题
  //
  // 1、dp数组的定义：dp[i][j]表示有i个0，j个1的子数组的长度

  // 2、递归公式：dp[i][j] 可以是前一个状态的推导出来
  // dp[i][j] 可以是 dp[i - zeroNum][j - oneNum] + 1;
  // 所以递归公式： dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);

  // 3、dp数组的初始值：初始状态即dp[0][0]表示有0个0，0个1的子数组长度，自然为0;

  // 4、遍历顺序：外层遍历物品，内层遍历背包容量（注意逆序遍历）
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  for (string str : strs) {
    int oneNums = 0;
    int zeroNums = 0;
    for (auto ch : str) {
      if (ch == '0')
        zeroNums++;
      else if (ch == '1')
        oneNums++;
    }

    // 遍历背包容量
    for (int i = m; i >= zeroNums; i--) {
      for (int j = n; j >= oneNums; j--) {
        dp[i][j] = max(dp[i][j], dp[i - zeroNums][j - oneNums] + 1);
      }
    }
  }
  return dp[m][n];
}

int change(int amount, vector<int>& coins) {
  // dp问题，coins表示硬币的面值类型
  // amount为目标总额，coins的取值是无限的
  // 1、dp[i]表示凑出总额为i的不同方案的数量
  // 2、初始化:dp[0]表示凑出总额为0元的方案，自然是0。dp[0] = 1
  // 3、递推公式：dp[i] += dp[i - value]
  // 此处的value就是在coins所有面值数组中某个面值的纸币。
  // 注意每种货币是无限多的，属于完全背包问题（dp背包容量应该顺序遍历）

  vector<int> dp(amount + 1, 0);

  dp[0] = 1;

  for (int i = 0; i < coins.size(); i++) {
    for (int j = coins[i]; j <= amount; j++) {
      dp[j] += max(dp[j], dp[j - coins[i]]);
    }
  }
  return dp[amount];
}

int combinationSum4(vector<int>& nums, int target) {
  // 这个题和硬币面值组合的题目类似
  // 1、dp[j]：目标和为j的组合数量为dp[j]
  // 2、初始化：dp[0]表示组合的和为0的组合数量，取1
  // 3、递推公式：dp[j] += dp[j - nums[i]];
  // tips. 数组汇总的每个元素是无限多的，所以是完全背包问题

  // 排列问题、外层循环使用背包、内层循环使用数组
  // 遍历背包的时候升序遍历

  vector<int> dp(target + 1, 0);
  dp[0] = 1;
  for (int i = 0; i <= target; i++) {
    for (int j = 0; j < nums.size(); j++) {
      if (i - nums[j] >= 0 && dp[i] < INT32_MAX - dp[i - nums[j]])
        dp[i] += dp[i - nums[j]];
    }
  }
  return dp[target];
}

int climbStairsII(int n, int maxStep) {
  // 爬楼梯动规的进阶
  // 假设每一步可以走最大maxStep步
  // 这就变成了完全背包问题，取值1<->m，背包容量n
  // 先走1步再走2步和先走2步再走1步是两种不同的方案，所以这是一个排列问题
  // 对于排列问题，需要把遍历背包放在外层

  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= maxStep; j++) {
      if (i - j >= 0) dp[i] += dp[i - j];
    }
  }
  return dp[n];
}

int coinChange(vector<int>& coins, int amount) {
  // 求得凑成金币的最少硬币个数，如果不能凑出来返回-1

  // 每种硬币是无限的
  // dp[i]表示凑出金额为i的最少金币个数
  // dp[0] = 0
  // 递推公式：dp[i]  = min(dp[i], dp[i - coins[j]] + 1);

  // 因为递推公式求min，所以dp数组初始值设置为INT32_MAX

  vector<int> dp(amount + 1, INT32_MAX);
  dp[0] = 0;

  // 硬币是无限的，遍历背包的时候升序遍历
  // 只计算凑成金额的硬币数量，所以是组合问题，
  // 组合问题，外层遍历数组、内层遍历背包

  // 外层遍历数组
  for (int i = 0; i < coins.size(); i++) {
    // 内层遍历背包可能的容量，而且因为是数组元素可以重复取，所以使用升序遍历
    for (int j = coins[i]; j <= amount; j++) {
      // 因为dp数组初始化为INT32_MAX，而且在递推公式中，
      // dp[j]可能等于dp[j - coins[i]] + 1，
      // 所以dp[j]有移除的可能性，溢出的话说明凑不出这样的金额，直接跳过
      if (dp[j - coins[i]] != INT32_MAX) {
        dp[j] = min(dp[j], dp[j - coins[i]] + 1);
      }
    }
  }
  // dp[amount]还是初始值，说明遍历不到这个位置，凑不出amount这个金额，
  // 直接返回-1
  if (dp[amount] == INT32_MAX) return -1;
  return dp[amount];
}

int numSquares(int n) {
  // 动规问题，翻译一下：
  // 完全平方数就是数组元素，而且可以无限使用
  // 凑出和为n的背包，求得背包中元素的最少个数，组合问题
  // dp[i]表示容量为i的背包的最少元素个数
  // 初始化为最大值，dp[0] = 0;
  // 递推公式: dp[i] = min(dp[i], dp[i - pow(j)] + 1)

  vector<int> dp(n + 1, INT32_MAX);
  dp[0] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = i * i; j <= n; j++) {
      if (dp[j - i * i] != INT32_MAX) {
        dp[j] = min(dp[j], dp[j - i * i] + 1);
      }
    }
  }
  return dp[n];
}

bool wordBreak(string s, vector<string>& wordDict) {
  // 用字典里面的字符串，无限使用，拼出字符串s
  // 动规问题，数组就是字典wordDict，背包就是s
  // 问题在于怎么拼接wordDict中的字符串从而和s相匹配呢
  // 想到了，从wordDict中拿出一个字符串，如果是字符串s的前缀的话，从s中把这个前缀删除,

  // 1、dp[i]表示字符串s的任意子串长度的时候能不能把被拼接表示
  // 2、确定初始值： dp[0] = true;
  // 3、递推公式：if(dp[j] && s[j : i]在wordDict中) 那么 dp[i] = true;
  // 因为可以无限使用，遍历背包升序遍历
  // 因为是排列问题，遍历背包应该在外层；遍历数字在内层

  unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

  vector<bool> dp(s.size() + 1, false);
  dp[0] = true;

  for (int i = 0; i <= s.size(); i++) {
    for (int j = 0; j < i; j++) {
      string word = s.substr(j, i - j);
      if (wordSet.find(word) != wordSet.end() && dp[j]) dp[i] = true;
    }
  }
  return dp[s.size()];
}

// 股票只能卖一次
// dp[i]表示的是i天以及以前的最低价
// int maxProfit(vector<int>& prices) {
//   int max_val = 0;
//   int minPrice = INT32_MAX;
//   int lastMinPrice = prices[0];
//   for (int i = 1; i < prices.size(); i++) {
//     minPrice = lastMinPrice <= prices[i] ? lastMinPrice : prices[i];
//     max_val = prices[i] - minPrice > max_val ? (prices[i] - minPrice) :
//     max_val;
//   }
//   return max_val;
// }

vector<int> countBits(int n) {
  // 记dp[i]表示i的二进制表示中1的个数
  // y = x & (x-1)，则y的二进制表示中1的个数是x的二进制表示中1的个数减一
  // dp[y] = dp[x & (x - 1)] +1

  vector<int> dp(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i & (i - 1)] + 1;
  }
  return dp;
}

vector<int> findDisappearedNumbers(vector<int>& nums) {
  vector<int> vec;
  unordered_set<int> uset;
  for (auto item : nums) uset.insert(item);
  for (int i = 1; i <= nums.size(); i++) {
    if (uset.find(i) == uset.end()) {
      vec.push_back(i);
    }
  }
  return vec;
}

int translateNum(int num) {
  // dp问题，dp[i]表示第i位可以分解成字母的个数
  if (num < 10) return 1;
  vector<int> nums;
  while (num > 0) {
    nums.push_back(num % 10);
    num /= 10;
  }

  nums.push_back(0);
  std::reverse(nums.begin(), nums.end());
  vector<int> dp(nums.size(), 0);
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i < nums.size(); i++) {
    int val = nums[i - 1] * 10 + nums[i];
    if (10 < val && val < 26) {
      dp[i] = dp[i - 1] + dp[i - 2];
    } else {
      dp[i] = dp[i - 1];
    }
  }
  return dp[nums.size() - 1];
}

int lengthOfLongestSubstring(string s) {
  if (s.size() <= 1) return s.size();
  unordered_set<char> char_set;
  int left = 0, right = 0;

  int max_count = 0;
  while (left <= right && right < s.size()) {
    while (left <= right && right < s.size() &&
           char_set.find(s[right]) == char_set.end()) {
      char_set.insert(s[right++]);
    }
    max_count = max(max_count, int(char_set.size()));
    char_set.erase(s[left++]);
  }
  return max_count;
}

// 动规，记dp[i]表示长度为i的绳子切分之后的最大乘积
// dp[1] = 0
// dp[2] = 1
// dp[i] = max(dp[i-j] * j, dp[j] * dp[i-j] ...)， j从1到i-1
// int cuttingRope(int n) {
//   vector<int> dp(n + 1, 0);
//   dp[1] = 0;
//   dp[2] = 1;
//   for (int i = 3; i <= n; i++) {
//     for (int j = 1; j <= i - 1; j++) {
//       dp[i] = max({dp[i], dp[i - j] * j, dp[i - j] * dp[j], j * (i - j)});
//     }
//   }
//   return dp[n];
// }

// dp[i]表示偷窃i房间的收益
// 初始化dp[0] = nums[0];
// dp[1] = nums[1];
// 递推公式: dp[i] = max(dp[i-2] + nums[i], dp[i-1])
// dp[i-2] + nums[i]表示偷前面第二个以及当前这个
// dp[i-1]表示当前这个不偷，所以状态和前一个一致

int robRange(vector<int>& nums, int start, int end) {
  if (start == end) return nums[start];
  vector<int> dp(nums.size(), 0);
  dp[start] = nums[start];
  dp[start + 1] = nums[start + 1];
  for (int i = start + 2; i <= end; i++) {
    dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
  }
  return dp[end];
}
int rob1(vector<int>& nums) {
  if (nums.empty()) return 0;
  if (nums.size() == 1) return nums[0];
  int discardHead = robRange(nums, 1, nums.size() - 1);
  int discardTail = robRange(nums, 0, nums.size() - 2);
  return max(discardHead, discardTail);
}

int rob(vector<int>& nums) {
  if (nums.empty()) return 0;
  if (nums.size() == 1) return nums[0];
  vector<int> dp(nums.size(), 0);
  dp[0] = nums[0];
  dp[1] = max(nums[0], nums[1]);
  for (int i = 2; i < nums.size(); i++) {
    dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
  }
  return dp[nums.size() - 1];
}

// dp[2]
// dp[0]:不打劫这个房间的收益
// dp[1]:打劫这个房间的收益

vector<int> rob_helper(TreeNode* root) {
  if (!root) return {0, 0};
  if (!root->left && !root->right) return {0, root->val};
  auto left = rob_helper(root->left);
  auto right = rob_helper(root->right);
  return {max(left[0], left[1]) + max(right[0], right[1]),
          left[0] + right[0] + root->val};
}

int rob(TreeNode* root) {
  auto vec = rob_helper(root);
  return max(vec[0], vec[1]);
}

// int maxProfit(vector<int>& prices) {
//   if (prices.size() <= 1) return 0;
//   vector<int> profit(prices.size() - 1, 0);
//   for (int i = 0; i < prices.size() - 1; i++) {
//     profit[i] = prices[i + 1] - prices[i];
//   }

//   vector<int> dp(profit.size(), 0);
//   dp[0] = max(0, profit[0]);
//   int max_profit = dp[0];
//   for (int i = 1; i < profit.size(); i++) {
//     dp[i] = max(dp[i - 1] + profit[i], profit[i]);
//     if (max_profit < dp[i]) max_profit = dp[i];
//   }
//   return max_profit;
// }

// dp[i][0]表示第i天持有股票的最大现金
// dp[i][1]表示第i天不持有股票的最大现金

// dp[i][0] = max(dp[i-1][0], -price[i]) :
// 要么是前一天已经是持有股票状态了，要么今天买入股票，金额减少prices[i]

// dp[i][1] = max(dp[i-1][1], prices[i] + dp[i-1][0])
// 要么前一天没有持有股票，要么今天卖出股票，那么当前最新持有的现金等于前一天持有股票的金额加上今天卖出股票的金额
int maxProfitI(vector<int>& prices) {
  if (prices.size() <= 1) return 0;
  vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
  dp[0][0] = -prices[0];

  for (int i = 1; i < prices.size(); i++) {
    dp[i][0] = max(dp[i - 1][0], -prices[i]);
    dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
  }
  return max(dp[0][prices.size() - 1], dp[1][prices.size() - 1]);
}

// 买卖股票、可以任意买卖，不限制交易次数

// dp[i][0]：表示第i天持有股票的利润
// dp[i][1]：表示第i天不持有股票的利润

// 第i天持有股票的金额，有两种可能，前一天已经持有股票了dp[i-1][0]
// 或者是今天买入股票，金额等于前一天没买的金额减去今天购买股票的金额dp[i-1][1]-
// prices[i]

// dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i])

// 第i天没有持有股票的金额，有两种可能，前一天没有持有股票，dp[i-1][1]
// 或者前一天持有股票，今天卖出股票dp[i-1][0] + prices[i]

// dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i])

// 随意交易次数
int maxProfitII(vector<int>& prices) {
  if (prices.size() <= 1) return 0;
  vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
  dp[0][0] = -prices[0];

  for (int i = 1; i < prices.size(); i++) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
  }
  int sz = prices.size() - 1;
  return max(dp[sz][0], dp[sz][1]);
}

// 只能交易两次
int maxProfi2(vector<int>& prices) {
  if (prices.size() <= 4) return 0;
  vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
  dp[0][1] = -prices[0];
  dp[0][3] = -prices[0];

  for (int i = 1; i < prices.size(); i++) {
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
    dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
    dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
  }

  return dp[prices.size() - 1][4];
}

// 最多交易k次
int maxProfit(int k, vector<int>& prices) {
  if (prices.size() == 0) return 0;
  vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
  for (int i = 1; i < 2 * k + 1; i += 2) {
    dp[0][i] = -prices[0];
  }
  for (int i = 1; i < prices.size(); i++) {
    for (int j = 0; j < k * 2 + 1; j += 2) {
      dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
      dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
    }
  }
  return dp[prices.size() - 1][2 * k];
}

// 具有一天冷冻期
int maxProfit(vector<int>& prices) {
  if (prices.size() == 0) return 0;
  vector<vector<int>> dp(prices.size(), vector<int>(4));

  dp[0][0] = -prices[0];

  for (int i = 1; i < prices.size(); i++) {
    dp[i][0] =
        max({dp[i - 1][0], dp[i - 1][3] - prices[i], dp[i - 1][1] - prices[i]});
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
    dp[i][2] = dp[i - 1][0] + prices[i];
    dp[i][3] = dp[i - 1][2];
  }
  return max({dp[prices.size() - 1][1], dp[prices.size() - 1][2],
              dp[prices.size() - 1][3]});
}

// 包含手续费
int maxProfit(vector<int>& prices, int fee) {
  if (prices.size() == 0) return 0;
  vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
  dp[0][0] = -prices[0];
  for (int i = 1; i < prices.size(); i++) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
  }
  return dp[prices.size() - 1][1];
}

//======= 3.20 =========
int lengthOfLIS(vector<int>& nums) {
  if (nums.empty()) return 0;
  if (nums.size() == 1) return 1;
  int result = 0;
  vector<int> dp(nums.size(), 1);

  for (int i = 1; i < nums.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
    }
    if (dp[i] > result) result = dp[i];
  }
  return result;
}

int minPathSum(vector<vector<int>>& grid) {
  int h = grid.size();
  int w = grid[0].size();
  vector<vector<int>> dp(h, vector<int>(w, 0));
  dp[0][0] = grid[0][0];
  for (int i = 1; i < h; i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
  for (int i = 1; i < w; i++) dp[0][i] = dp[0][i - 1] + grid[0][i];
  for (int i = 1; i < h; i++) {
    for (int j = 1; j < w; j++) {
      dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
    }
  }
  return dp[h - 1][w - 1];
}

int maxProduct(vector<int>& nums) {
  vector<int> dp(nums.size(), 0);
  dp[0] = nums[0];
  int max_val = dp[0];
  for (int i = 1; i < nums.size(); i++) {
    dp[i] = dp[i - 1] * nums[i] > nums[i] ? dp[i - 1] * nums[i] : nums[i];
    max_val = max(max_val, dp[i]);
  }
  return max_val;
}

int findLengthOfLCIS(vector<int>& nums) {
  if (nums.empty()) return 0;
  if (nums.size() == 1) return 1;
  vector<int> dp(nums.size(), 1);
  int result = 0;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] > nums[i - 1]) dp[i]++;
    result = max(result, dp[i]);
  }
  return result;
}

// dp问题，dp[i][j]表示在数组nums1中以i-1结尾的子串，在数组nums2中以j-1结尾的子串中，公共最长子数组的长度
// 如果nums1[i] == nums2[j] ，那么dp[i][j] = dp[i-1][j-1] + 1
// 初始化dp[0][0] = 0
int findLength(vector<int>& nums1, vector<int>& nums2) {
  vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
  int result = 0;
  for (int i = 1; i <= nums1.size(); i++) {
    for (int j = 1; j <= nums2.size(); j++) {
      if (nums1[i - 1] == nums2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      if (dp[i][j] > result) result = dp[i][j];
    }
  }
  return result;
}

// dp[i][j]表示在text1中前面0到i-1的子串中，以及在text2中前面0到j-1的子串中，具有的最长公共子序列的长度。
int longestCommonSubsequence(string text1, string text2) {
  vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
  for (int i = 1; i <= text1.size(); i++) {
    for (int j = 1; j <= text2.size(); j++) {
      if (text1[i - 1] == text2[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[text1.size()][text2.size()];
}

// dp[i][j]表示前一个数组的前i-1个范围内，后一个数组j-1的范围内，最大的公共非连续前缀是dp[i][j]
int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
  int sz1 = nums1.size();
  int sz2 = nums2.size();
  vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1, 0));

  for (int i = 1; i <= sz1; i++) {
    for (int j = 1; j <= sz2; j++) {
      if (nums1[i - 1] == nums2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[sz1][sz2];
}

// dp[i]表示以i结尾的最大子数组和为dp[i]
int maxSubArray(vector<int>& nums) {
  vector<int> dp(nums.size(), 0);
  dp[0] = nums[0];
  int reslut = dp[0];
  for (int i = 1; i < nums.size(); i++) {
    dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    reslut = max(dp[i], reslut);
  }
  return reslut;
}

// dp[i][j]表示s中前i-1的子串和t中j-1的子串的相同序列个数，可以不连续
bool isSubsequence(string s, string t) {
  int sz1 = s.size();
  int sz2 = t.size();

  vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1, 0));
  for (int i = 1; i <= sz1; i++) {
    for (int j = 1; j <= sz2; j++) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return sz1 == dp[sz1][sz2];
}

// 计算t在s的子序列中出现的次数
// s=rabbit，t=rabbbit，就返回3
// dp[i][j]表示在s中的前i-1的子串和t中j-1的子串之间的匹配子串数
// if(dp[i][j] == dp[i-1][j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
// else dp[i][j] = dp[i-1][j]
int numDistinct(string s, string t) {
  uint64_t sz1 = s.size();
  uint64_t sz2 = t.size();
  vector<vector<uint64_t>> dp(sz1 + 1, vector<uint64_t>(sz2 + 1, 0));
  for (uint64_t i = 0; i < sz1; i++) dp[i][0] = 1;
  for (uint64_t i = 1; i <= sz1; i++) {
    for (uint64_t j = 1; j <= sz2; j++) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[sz1][sz2];
}

}  // namespace dp