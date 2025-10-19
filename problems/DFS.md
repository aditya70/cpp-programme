
## 🟢 **Easy (Intro to DFS – recursion & grid traversal)**

| Problem                                                                      | Topic       | Notes                                                               |
| ---------------------------------------------------------------------------- | ----------- | ------------------------------------------------------------------- |
| [200. Number of Islands](https://leetcode.com/problems/number-of-islands/)   | DFS on Grid | Classic connected-component problem; mark visited land recursively. |
| [695. Max Area of Island](https://leetcode.com/problems/max-area-of-island/) | DFS on Grid | Similar to above, but return island size.                           |
| [733. Flood Fill](https://leetcode.com/problems/flood-fill/)                 | DFS on Grid | Basic DFS recoloring — great warm-up.                               |

---

## 🟡 **Medium (Recursive & Backtracking DFS)**

| Problem                                                                                        | Topic                     | Notes                                                  |
| ---------------------------------------------------------------------------------------------- | ------------------------- | ------------------------------------------------------ |
| [79. Word Search](https://leetcode.com/problems/word-search/)                                  | DFS + Backtracking (Grid) | Explore all 4 directions, mark/unmark visited.         |
| [417. Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/) | DFS from Multiple Sources | Run DFS from both oceans, find overlap.                |
| [207. Course Schedule](https://leetcode.com/problems/course-schedule/)                         | DFS Cycle Detection       | Detect cycles in directed graph using recursion stack. |
| [78. Subsets](https://leetcode.com/problems/subsets/)                                          | DFS + Backtracking        | Generate all subsets by recursive include/exclude.     |
| [39. Combination Sum](https://leetcode.com/problems/combination-sum/)                          | DFS + Backtracking        | Explore all sums allowing reuse of elements.           |

---

## 🔴 **Hard (Advanced recursion & pruning)**

| Problem                                                                                          | Topic                   | Notes                                          |
| ------------------------------------------------------------------------------------------------ | ----------------------- | ---------------------------------------------- |
| [212. Word Search II](https://leetcode.com/problems/word-search-ii/)                             | DFS + Trie              | Combine DFS with Trie for efficient pruning.   |
| [51. N-Queens](https://leetcode.com/problems/n-queens/)                                          | DFS + Backtracking      | Place queens safely row by row.                |
| [124. Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/) | DFS + Tree State Return | Return max gain per subtree, track global max. |

---

✅ **9 core problems total** — this set covers:

* Grid traversal
* Backtracking recursion
* Graph cycle detection
* Tree DFS with state return


A
## 💡 Intuition Summary

| Concept                      | Meaning                               | Example                             |
| ---------------------------- | ------------------------------------- | ----------------------------------- |
| **DFS (Depth-First Search)** | Explore all possible combinations     | Go as deep as possible with [2,2,3] |
| **Backtracking**             | Undo the last choice and try another  | Pop `3` → try next number           |
| **Pruning**                  | Stop exploring impossible paths early | When candidate > remaining target   |


