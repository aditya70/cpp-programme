 **Dynamic Programming (DP) problem roadmap** s
---

## 🟢 **Beginner / Introductory DP**

These problems introduce **state definition**, **recurrence relations**, and **memoization**.

| Problem                                                                                                | Topic               | Notes                                        |
| ------------------------------------------------------------------------------------------------------ | ------------------- | -------------------------------------------- |
| [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)                                  | Fibonacci DP        | Classic 1D DP — `dp[i] = dp[i-1] + dp[i-2]`. |
| [198. House Robber](https://leetcode.com/problems/house-robber/)                                       | Linear DP           | Choose to rob or skip each house.            |
| [746. Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/)               | 1D DP               | Transition cost from last two steps.         |
| [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | DP (1 transaction)  | Track min price and max profit.              |
| [303. Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)           | Prefix Sum (pre-DP) | Foundation for DP prefix sums.               |
| [1137. N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/)                  | Fibonacci variant   | Great for iterative DP warm-up.              |

---

## 🟡 **Intermediate DP**

These problems strengthen your grasp on **state transitions**, **subproblem reuse**, and **2D DP**.

| Problem                                                                                              | Topic              | Notes                                          |
| ---------------------------------------------------------------------------------------------------- | ------------------ | ---------------------------------------------- |
| [213. House Robber II](https://leetcode.com/problems/house-robber-ii/)                               | Circular DP        | Handle first/last overlap.                     |
| [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)                              | Kadane’s Algorithm | DP on running subarray sum.                    |
| [91. Decode Ways](https://leetcode.com/problems/decode-ways/)                                        | String DP          | Count decodings with constraints.              |
| [62. Unique Paths](https://leetcode.com/problems/unique-paths/)                                      | Grid DP            | `dp[i][j] = dp[i-1][j] + dp[i][j-1]`.          |
| [64. Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/)                              | Grid DP            | Add grid weights to Unique Paths.              |
| [139. Word Break](https://leetcode.com/problems/word-break/)                                         | String DP          | Segment string using dictionary words.         |
| [322. Coin Change](https://leetcode.com/problems/coin-change/)                                       | Unbounded Knapsack | Min coins to reach amount.                     |
| [300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) | Sequence DP        | `dp[i] = 1 + max(dp[j]) if nums[j] < nums[i]`. |

---

## 🔵 **Advanced DP**

Here you’ll see **multiple dimensions**, **bitmasking**, **state compression**, or **sequence comparison**.

| Problem                                                                                                                            | Topic                 | Notes                                    |
| ---------------------------------------------------------------------------------------------------------------------------------- | --------------------- | ---------------------------------------- |
| [416. Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/)                                       | Subset Sum DP         | 0/1 knapsack boolean DP.                 |
| [494. Target Sum](https://leetcode.com/problems/target-sum/)                                                                       | Subset Sum (sum diff) | Transform into subset-sum count problem. |
| [474. Ones and Zeroes](https://leetcode.com/problems/ones-and-zeroes/)                                                             | 2D Knapsack           | Two resource limits: 0s and 1s.          |
| [1143. Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)                                      | 2D String DP          | `dp[i][j] = dp[i-1][j-1]+1` if match.    |
| [72. Edit Distance](https://leetcode.com/problems/edit-distance/)                                                                  | 2D Edit DP            | Insert/delete/replace transitions.       |
| [97. Interleaving String](https://leetcode.com/problems/interleaving-string/)                                                      | 2D Merge DP           | Combine two strings into a target.       |
| [115. Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)                                                 | 2D Count DP           | Count subsequences matching target.      |
| [309. Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) | State DP              | States = buy/sell/cooldown.              |

---

## 🟣 **Expert / State Compression & Hard DP**

These require **bitmasking**, **optimization**, or **multi-step reasoning**.

| Problem                                                                                                        | Topic            | Notes                                  |
| -------------------------------------------------------------------------------------------------------------- | ---------------- | -------------------------------------- |
| [188. Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)   | k-transaction DP | DP[k][day][hold].                      |
| [123. Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/) | 2-transaction DP | Simplified version of above.           |
| [221. Maximal Square](https://leetcode.com/problems/maximal-square/)                                           | 2D DP on grid    | `dp[i][j] = 1 + min(top, left, diag)`. |
| [312. Burst Balloons](https://leetcode.com/problems/burst-balloons/)                                           | Interval DP      | `dp[i][j] = max(dp[i][k]+dp[k][j])`.   |
| [1547. Minimum Cost to Cut a Stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/)                | Interval DP      | Similar to Burst Balloons.             |
| [887. Super Egg Drop](https://leetcode.com/problems/super-egg-drop/)                                           | Mathematical DP  | Min worst-case moves for k eggs.       |
| [879. Profitable Schemes](https://leetcode.com/problems/profitable-schemes/)                                   | 3D DP            | Knapsack variant with constraints.     |
| [691. Stickers to Spell Word](https://leetcode.com/problems/stickers-to-spell-word/)                           | Bitmask + Memo   | Hard state reduction problem.          |
| [312. Burst Balloons](https://leetcode.com/problems/burst-balloons/)                                           | Interval DP      | Maximize coins with split points.      |

---

## ⚡ **Bonus: Common DP Patterns**

| Pattern                   | Example Problems                  | Core Idea                           |
| ------------------------- | --------------------------------- | ----------------------------------- |
| **1D Linear DP**          | Climbing Stairs, House Robber     | `dp[i]` depends on last 1–2 states. |
| **2D Grid DP**            | Unique Paths, Minimum Path Sum    | Transition from top/left cells.     |
| **Knapsack Variants**     | Coin Change, Target Sum           | Capacity-based optimization.        |
| **String Subsequence DP** | LCS, Edit Distance                | Compare prefixes.                   |
| **Partition DP**          | Burst Balloons, Stick Cutting     | `dp[i][j]` from partitions.         |
| **State Machine DP**      | Stock Buy/Sell, Cooldown          | Maintain different “states.”        |
| **Bitmask DP**            | Traveling Salesman, Keys Problems | State = subset of elements.         |

---
- 309: state machine dynamic programming problem. This one is key for understanding DP on states / transitions, often used in stock trading problems and general “finite-state” dynamic systems.



