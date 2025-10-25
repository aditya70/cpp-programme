
---

## 🧭 **1. The DP Mindset: Recognizing a DP Problem**

Dynamic Programming problems share 3 core traits.
If you see **any two**, it’s probably DP.

| Signal                      | What It Means                                                    | Example                                                |
| --------------------------- | ---------------------------------------------------------------- | ------------------------------------------------------ |
| **Overlapping Subproblems** | You recompute the same result multiple times.                    | Fibonacci numbers — `f(n)` uses `f(n-1)` and `f(n-2)`. |
| **Optimal Substructure**    | The optimal solution is built from optimal sub-results.          | Shortest path, minimum cost problems.                  |
| **Decision at Each Step**   | You must choose one of multiple actions (take/skip, left/right). | Knapsack, House Robber, Coin Change.                   |

👉 If your recursion reuses results → it’s DP.

---

## 🧩 **2. How to Approach Any DP Problem (5-Step Template)**

### **Step 1: Define the State**

Ask: *“What does my subproblem represent?”*
Usually, `dp[i]` or `dp[i][j]` means “best answer up to index i (or i, j).”

🧠 Examples:

* `dp[i]`: Max profit up to day i.
* `dp[i][j]`: LCS length for first i chars of A, first j chars of B.
* `dp[mask][i]`: Minimum cost to visit subset `mask` ending at node i.

---

### **Step 2: Write the Recurrence Relation**

Ask: *“If I knew answers to smaller subproblems, how do I build the bigger one?”*

🧠 Examples:

* **Climbing Stairs:** `dp[i] = dp[i-1] + dp[i-2]`
* **Knapsack:** `dp[i][w] = max(dp[i-1][w], dp[i-1][w-weight[i]] + value[i])`
* **Edit Distance:**
  `dp[i][j] = min(insert, delete, replace)`

---

### **Step 3: Initialize Base Cases**

Set your starting point.

* Climbing stairs → `dp[0] = 1`
* Knapsack → `dp[0][*] = 0`
* LCS → `dp[0][*] = dp[*][0] = 0`

---

### **Step 4: Fill the DP Table (Bottom-Up or Top-Down)**

Two equivalent approaches:

* **Top-down (memoization):** recursion + cache
* **Bottom-up (tabulation):** iterative filling.

🧠 Tip: Start small and “grow” the subproblems.

---

### **Step 5: Return the Final Answer**

Usually the last cell: `dp[n-1]`, `dp[m][n]`, or `max(dp[*])`.

---

## 🧮 **3. Common DP Problem Families**

You’ll notice repeating patterns across categories — learn to *map* problems to these.

| Pattern                   | Keywords / Signs                                                   | Examples                                    |
| ------------------------- | ------------------------------------------------------------------ | ------------------------------------------- |
| **Fibonacci / Linear DP** | “Nth ways / count / min cost / max sum”                            | Climbing Stairs, House Robber               |
| **Knapsack / Subset Sum** | “Pick or skip”, “Sum = target”                                     | 0/1 Knapsack, Partition Equal Subset        |
| **Grid / Matrix DP**      | “Move right/down”, “Path sum”, “Shortest route”                    | Unique Paths, Minimum Path Sum              |
| **String DP**             | “Compare two strings”, “Subsequence”, “Transform one into another” | Edit Distance, LCS                          |
| **Interval DP**           | “Split array/segment/interval optimally”                           | Burst Balloons, Matrix Chain Multiplication |
| **State Machine DP**      | “Buy/sell/hold/cooldown”, “Job scheduling”                         | Stock Buy/Sell problems                     |
| **Bitmask DP**            | “All combinations/subsets”, “Visit all nodes”                      | Traveling Salesman, Collect Keys            |
| **Counting DP**           | “Count ways, not min/max”                                          | Decode Ways, Coin Change II                 |

---

## ⚡ **4. Tricks and Heuristics**

### 🧠 **Trick 1: If your recursion tree repeats — memoize it**

If you find yourself saying “we’re recomputing this,” that’s DP.

```cpp
int solve(int n, vector<int>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = solve(n-1, memo) + solve(n-2, memo);
}
```

---

### 🧠 **Trick 2: Reduce Dimensions**

Many 2D DPs can be optimized to 1D using rolling arrays.

* Example: **LCS, Edit Distance**

  ```cpp
  vector<int> prev(n+1), cur(n+1);
  ```

  Update `cur[j]` using only `prev[j]` and `cur[j-1]`.

---

### 🧠 **Trick 3: Think in Reverse**

Sometimes it’s easier to go backward (e.g., from end to start).

* Coin Change, Decode Ways — reverse traversal often simplifies recurrence.

---

### 🧠 **Trick 4: Use Prefix or Suffix Arrays**

* Convert O(n²) DP into O(n) using precomputed sums.
* Example: Range sum, palindrome partitioning, subsequence counts.

---

### 🧠 **Trick 5: Bitmask DP for Combinations**

When dealing with subsets, encode them as bits:

* Example: **Traveling Salesman**

  ```cpp
  dp[mask][i] = min over j (dp[mask ^ (1 << i)][j] + cost[j][i]);
  ```

---

### 🧠 **Trick 6: Memoize on All Varying Parameters**

If your recursive function depends on `(i, j, remaining, last, sum)`,
you must memoize on all of them.

---

## 🔍 **5. How to Identify a DP Problem in the Wild**

Ask these diagnostic questions:

1. **Do I need to find min/max/count/ways?** → likely DP.
2. **Can I define the problem in terms of smaller versions of itself?**
3. **Are there overlapping subproblems (same inputs recur)?**
4. **Does greedy or sorting fail because of interdependencies?**
5. **Is recursion leading to exponential time?** → add DP.

💡 *If brute force = exponential and solutions overlap → 99% it’s DP.*

---

## 🧱 **6. Progression Path to Master DP**

| Stage      | Focus                              | Example                            |
| ---------- | ---------------------------------- | ---------------------------------- |
| 🟢 Stage 1 | 1D DP (Fibonacci, Climbing Stairs) | Build base intuition               |
| 🟡 Stage 2 | 2D DP (Grids, Strings)             | Learn transition logic             |
| 🔵 Stage 3 | Knapsack Variants                  | Handle choices/weights             |
| 🟣 Stage 4 | State + Interval DP                | Combine multiple parameters        |
| ⚫ Stage 5  | Bitmask + Optimization             | Compress states, reduce space/time |

---

## 🚀 **7. Pro Tips for Practice**

* 🔁 Re-solve each problem **3 times** — first with recursion, then memo, then bottom-up.
* 📈 Track your `dp[i]` meaning clearly in comments.
* 🧾 Write recurrence by hand before coding.
* ⚙️ Simulate small examples step-by-step.
* 🔍 Print your DP table (small inputs) — helps visualize transitions.
* ⏱ Learn to detect *redundant states* → simplify space/time.
* 💡 Convert recursion to iterative logic gradually.

---

