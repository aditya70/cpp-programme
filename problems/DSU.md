 **DSU (DisJoinSet Union) / Union-Find** problems 

---

## 🟢 **Easy (Intro to Union-Find – basic union & find)**

| Problem                                                                                                                               | Topic                     | Notes                                               |
| ------------------------------------------------------------------------------------------------------------------------------------- | ------------------------- | --------------------------------------------------- |
| [547. Number of Provinces](https://leetcode.com/problems/number-of-provinces/)                                                        | Union-Find / Graph        | Count connected components in an undirected graph.  |
| [1319. Number of Operations to Make Network Connected](https://leetcode.com/problems/number-of-operations-to-make-network-connected/) | Union-Find / Connectivity | Connect nodes; check if network is fully connected. |
| [990. Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations/)                      | Union-Find / Logic        | Combine equality relations, detect contradictions.  |

---

## 🟡 **Medium (Classic DSU applications)**

| Problem                                                                              | Topic                 | Notes                                        |
| ------------------------------------------------------------------------------------ | --------------------- | -------------------------------------------- |
| [721. Accounts Merge](https://leetcode.com/problems/accounts-merge/)                 | Union-Find / Merge    | Merge accounts by connecting emails.         |
| [839. Similar String Groups](https://leetcode.com/problems/similar-string-groups/)   | Union-Find / Grouping | Strings connected if they differ by 2 swaps. |
| [959. Regions Cut By Slashes](https://leetcode.com/problems/regions-cut-by-slashes/) | Union-Find / Grid     | Split grid into regions using DSU.           |

---

## 🔴 **Hard (Advanced DSU / Optimization)**

| Problem                                                                                                                | Topic                     | Notes                                                               |
| ---------------------------------------------------------------------------------------------------------------------- | ------------------------- | ------------------------------------------------------------------- |
| [952. Largest Component Size by Common Factor](https://leetcode.com/problems/largest-component-size-by-common-factor/) | Union-Find + Math         | Factorize numbers, connect via common factors.                      |
| [847. Shortest Path Visiting All Nodes](https://leetcode.com/problems/shortest-path-visiting-all-nodes/)               | Union-Find / BFS Mix      | Can be solved with DSU for connectivity check (alternative BFS).    |
| [1627. Graph Connectivity With Threshold](https://leetcode.com/problems/graph-connectivity-with-threshold/)            | Union-Find / Connectivity | Connect nodes with factor > threshold, answer connectivity queries. |

---

✅ **9 core DSU problems total**, covering:

* Basic connected components
* Merging sets (accounts, strings)
* Grid and factorization problems
* Connectivity checks and union optimizations


----
**4-day progressive DSU practice plan** 
---

## **🗓 Day 1 – Basics of Union-Find (Easy)**

| Problem                                                                                                                               | Focus                                      | Goal                                                     |
| ------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------ | -------------------------------------------------------- |
| [547. Number of Provinces](https://leetcode.com/problems/number-of-provinces/)                                                        | Basic DSU / connected components           | Implement Union-Find `find` + `union`, count components. |
| [990. Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations/)                      | Union-Find logic / contradiction detection | Learn how to detect conflicts using DSU.                 |
| [1319. Number of Operations to Make Network Connected](https://leetcode.com/problems/number-of-operations-to-make-network-connected/) | Connectivity check                         | Check if network is connected after unions.              |

**✅ Focus:**

* Implement `parent[]` and `rank[]`.
* Practice path compression and union by rank (optional at this stage).

---

## **🗓 Day 2 – Classic DSU Applications (Medium)**

| Problem                                                                              | Focus                 | Goal                                                                |
| ------------------------------------------------------------------------------------ | --------------------- | ------------------------------------------------------------------- |
| [721. Accounts Merge](https://leetcode.com/problems/accounts-merge/)                 | Merge sets via emails | Connect multiple elements (emails) in the same set.                 |
| [839. Similar String Groups](https://leetcode.com/problems/similar-string-groups/)   | Grouping elements     | Learn union for abstract relationships (strings differ by 2 swaps). |
| [959. Regions Cut By Slashes](https://leetcode.com/problems/regions-cut-by-slashes/) | Grid + DSU            | Represent 2D regions as nodes and use DSU to merge.                 |

**✅ Focus:**

* Mapping elements (emails, strings, grid cells) to DSU nodes.
* Practice `union` on complex elements, not just integers.

---

## **🗓 Day 3 – Hard DSU (Advanced Merging & Optimization)**

| Problem                                                                                                                | Focus                    | Goal                                                  |
| ---------------------------------------------------------------------------------------------------------------------- | ------------------------ | ----------------------------------------------------- |
| [952. Largest Component Size by Common Factor](https://leetcode.com/problems/largest-component-size-by-common-factor/) | DSU + Math               | Merge numbers sharing factors; factorization + union. |
| [1627. Graph Connectivity With Threshold](https://leetcode.com/problems/graph-connectivity-with-threshold/)            | Connectivity + threshold | Answer multiple connectivity queries efficiently.     |

**✅ Focus:**

* DSU for non-trivial relationships (numbers via factors, threshold conditions).
* Optimize DSU with path compression and union by rank.

---

## **🗓 Day 4 – DSU in Mixed Contexts (Hard / Challenge)**

| Problem                                                                                                  | Focus            | Goal                                                       |
| -------------------------------------------------------------------------------------------------------- | ---------------- | ---------------------------------------------------------- |
| [847. Shortest Path Visiting All Nodes](https://leetcode.com/problems/shortest-path-visiting-all-nodes/) | DSU + BFS hybrid | Use DSU for connectivity checks before BFS/DP exploration. |
| Optional: revisit any problem you found difficult                                                        | -                | Solidify concepts                                          |

**✅ Focus:**

* Integrating DSU with other techniques (graph BFS, DP).
* Be comfortable switching between DSU and graph traversal.

---

### **Tips for DSU Practice**

1. Always **draw the sets and parents** on paper first for tricky problems.
2. Use **path compression** in `find` to reduce time complexity.
3. For merging multiple elements, **map each element to an integer ID** for DSU indexing.
4. After each problem, **check how `union` and `find` are applied differently** — e.g., merging emails vs numbers.
5. Connected, Merge, Group, relationship, similar, identical, equivalent problems

---

