# 树形dp问题

- 【打家劫舍三】https://leetcode.cn/problems/house-robber-iii/

# 买卖股票问题

- 只能买卖一次
- 买卖次数不受限制
- 最多买卖2次
- 最多买卖k次
- 售出之后有冷冻期的买卖股票
- 买卖有手续费的买卖股票

## 只能买卖一次

动规问题，dp[i][0]表示第i天持有股票的现金，dp[i][1]表示第i天不持有股票的现金
dp[i][0]:表示第i天持有股票的现金，由两种可能

- 前一天已经持有股票 dp[i][0] = dp[i-1][0]
- 前一天没有持有股票，需要今天买入股票 dp[i][0] = -prices[i]

> 注意只需要交易一次股票

dp[i][1]: 表示第i天不持有股票的新建，有两种可能

- 前一天没有持有股票： dp[i][1] = dp[i-1][1]
- 前一天持有股票，那就需要今天当天卖出股票：dp[i][1] = dp[i-1][0] + prices[i]

```cpp
// 状态转移方程
dp[i][0] = max(dp[i - 1][0], -prices[i]);
dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
```

```cpp
// 只买卖一次
int maxProfit(vector<int>& prices) {
  if (prices.size() <= 1) return 0;
  vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
  dp[0][0] = -prices[0];

  for (int i = 1; i < prices.size(); i++) {
    dp[i][0] = max(dp[i - 1][0], -prices[i]);
    dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
  }
  // 其中1表示最终只需要关注已经交易完成的情况
  return dp[1][prices.size() - 1];
}

```

---

## 买卖次数不受限制

dp[i][0]表示第i天持有股票的现金，有两种情况：

- 前一天已经持有股票：dp[i][0] = dp[i-1][0]
- 前一天没有持有股票，需要当天买入 dp[i][0] = dp[i-1][1] - prices[i]

dp[i][1]表示第i天不持有股票的现金，有两种情况：

- 前一天不持有股票：dp[i][1] = dp[i-1][1]
- 前一天持有股票，需要当天卖出dp[i][1] = dp[i-1][0] + prices[i]

```cpp
// 状态转移方程
dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] -prices[i]);
dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
```

```cpp
// 买卖次数不受限制
int maxProfit(vector<int>& prices) {
  if (prices.size() <= 1) return 0;
  vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
  dp[0][0] = -prices[0];

  for (int i = 1; i < prices.size(); i++) {
    dp[i][0] = max(dp[i - 1][0], -prices[i]);
    dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
  }
  // 其中1表示最终只需要关注已经交易完成的情况
  return dp[1][prices.size() - 1];
}

```

---

## 只能买卖两次

只能买卖两次，dp[i][j]
其中i表示某天
j为[0-4]个状态：

- 1： 第一次持有股票
- 2： 第一次卖出股票
- 3： 第二次持有股票
- 4： 第二次卖出股票

第一次持有股票，两种情况，前一天已经持有，或者今天当天买入

- dp[i][1] = dp[i-1][1]
- dp[i][1] = dp[i][0] - prices[i]

dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])

第一次卖出股票，两种情况，前一天仍然持有股票，那就今天卖出，前一天已经卖出了，那和昨天保持一致

- dp[i][2] = dp[i-1][2]
- dp[i][2] = dp[i-1][1] + prices[i]

dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i])

依次类推，第二次买入股票，有两种情况：

- 前一天已经第二次买入了： dp[i][3] = dp[i-1][3]
- 前一天是第一次卖出，需要今天当天买入： dp[i][3] = dp[i-1][2] - prices[i]

dp[i][3] = max(dp[i-1][3], dp[i-1][2]- prices[i])

依次类推，第二次卖出股票，有两种情况：

- 前一天已经第二次卖出股票了dp[i][4] = dp[i-1][4]
- 前一天没有卖出股票，需要今天当天卖出dp[i][4] = dp[i-1][3] + prices[i]

dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i])

```cpp
// 状态转移方程
dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
```

```cpp
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
```

---

## 可以买卖k次

这个直接参考最多可以交易2次的题目。
dp[i][j] 表示天数为i，状态为j的时候的金额。
包括dp[i][0]、dp[i][1]、dp[i][2]、dp[i][3]、dp[i][4]、dp[i][5]...

当k为偶数的时候：表示此时不持有股票的金额，有两种情况

- 前一天也没有持有股票
- 或者之前持有股票，当天卖出

dp[i][k] = max(dp[i-1][k], dp[i-1][k-1] + price[i])

当k为奇数的时候，表示此时持有股票。分为两种情况：

- 前一天持有股票：
- 前一天不持有股票，当天买入股票

dp[i][k] = max(dp[i-1][k], dp[i-1][k-1] - prices[i])

> 根据奇数偶数找状态转移方程之间的规律

```cpp
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
```

---

## 包含冷冻期的买卖股票

> https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/

![20230319204812](https://note-img-1300721153.cos.ap-nanjing.myqcloud.com/md-img20230319204812.png)

> 包含冷冻期的买卖股票的状态转移图

dp[i][j]表示第i天，处于状态j的金额。i表示天数，j为状态，按照上图有四种状态：

- 状态0：买入状态 dp[i][0] = max({dp[i-1][0], dp[i-1][3] - prices[i], dp[i-1][1] - prices[i]})
  - 昨天已经是买入的状态: dp[i][0] = dp[i-1][0]
  - 今天买入：
    - 今天买入，昨天是冷冻期：dp[i][0] = dp[i-1][3] - prices[i]
    - 今天买入，昨天是卖出状态：dp[i][0] = dp[i-1][1] - prices[i]
- 状态1：卖出状态 dp[i][1] = max(dp[i-1][1], dp[i-1][3])
  - 昨天已经是卖出状态：dp[i][1] = dp[i-1][1]
  - 昨天是冷冻期：dp[i][1] = dp[i-1][3]
- 状态2：今天卖出，只有一种可能，昨天已经处于买入状态: dp[i][2] = dp[i-1][0] + prices[i]
- 状态4：冷冻状态，只有一种可能，昨天当天卖出: dp[i][3] = dp[i-1][2]

```cpp
// 全部的状态转移方程：
dp[i][0] = max({dp[i - 1][0], dp[i - 1][3] - prices[i], dp[i - 1][1] - prices[i]})
dp[i][1] = max(dp[i - 1][1], dp[i - 1][3])
dp[i][2] = dp[i - 1][0] + prices[i]
dp[i][3] = dp[i - 1][2]
```

```cpp
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
```

---

## 包含手续费的买卖股票

> https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

dp[i][j]，其中i表示天数，j表示什么状态：

- j为0：持有状态
  - 前一天的状态已经是持有状态：dp[i][0] = dp[i-1][0]
  - 前一天是不持有状态，需要当天购入： dp[i][0] = dp[i-1][1] - prices[i]
- j为1：不持有状态
  - 前一天就是不持有状态： dp[i][1] = dp[i-1][1]
  - 前一天持有，当天卖出，需要附加手续费： dp[i][1] = dp[i-1][0] + prices[i] - fee

```cpp
// 所有的状态转移方程
dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
```

```cpp
// 包含手续费
int maxProfit(vector<int>& prices, int fee) {
  if (prices.size() == 0) return 0;
  vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
  dp[0][0] = -prices[0];
  for (int i = 1; i < prices.size(); i++) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
  }
  return dp[prices.size()-1][1];
}
```



## 背包问题

- 01背包
- 完全背包
- 分组背包