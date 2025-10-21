---

# 🚀 **Dijkstra Algorithm — LeetCode Practice Sheet**

---

## 🧩 **Level 1: Basic / Introductory (Shortest Path Foundation)**

| #                                                                                                                                             | Problem                                                               | Concept                                                                  | Notes |
| --------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------- | ------------------------------------------------------------------------ | ----- |
| [743. Network Delay Time](https://leetcode.com/problems/network-delay-time/)                                                                  | Dijkstra on weighted directed graph                                   | ✅ Classic starter — standard Dijkstra implementation with adjacency list |       |
| [1514. Path with Maximum Probability](https://leetcode.com/problems/path-with-maximum-probability/)                                           | Modified Dijkstra (maximize probability instead of minimize distance) | Use `max-heap` instead of min-heap                                       |       |
| [1631. Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/)                                                     | Grid-based Dijkstra                                                   | Each grid cell = node, edge weight = absolute diff                       |       |
| [505. The Maze II](https://leetcode.com/problems/the-maze-ii/)                                                                                | Grid + Dijkstra                                                       | Ball rolls until hitting a wall → cost accumulates                       |       |
| [1786. Number of Restricted Paths From First to Last Node](https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/) | Dijkstra + DP                                                         | Compute shortest path distances first, then DP on distance order         |       |

---

## ⚙️ **Level 2: Intermediate (Weighted Graph + Variations)**

| #                                                                                                                           | Problem                                 | Concept                                                   | Notes |
| --------------------------------------------------------------------------------------------------------------------------- | --------------------------------------- | --------------------------------------------------------- | ----- |
| [787. Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)                      | Dijkstra + BFS hybrid                   | Limit by number of stops (`K`); use `(node, cost, stops)` |       |
| [2093. Minimum Cost to Reach City With Discounts](https://leetcode.com/problems/minimum-cost-to-reach-city-with-discounts/) | Dijkstra + state `(node, discountUsed)` | Multi-dimensional Dijkstra                                |       |
| [2290. Minimum Obstacle Removal to Reach Corner](https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/)   | 0–1 BFS / Dijkstra                      | Edge weights are 0 or 1 (use deque for optimization)      |       |
| [1976. Number of Ways to Arrive at Destination](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/)     | Dijkstra + path counting                | Keep track of shortest distance and number of ways        |       |

---

## 🧠 **Level 3: Advanced (Multi-State, Modified Weights, or Grids)**

| #                                                                                                                                           | Problem                                       | Concept                                        | Notes |
| ------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------- | ---------------------------------------------- | ----- |
| [499. The Maze III](https://leetcode.com/problems/the-maze-iii/)                                                                            | Dijkstra + path reconstruction                | Lexicographically smallest path + min distance |       |
| [2662. Minimum Cost of a Path With Special Roads](https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/)                 | Dijkstra + coordinate compression             | Combine direct Euclidean edges + special roads |       |
| [2203. Minimum Weighted Subgraph With the Required Paths](https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/) | Multi-source Dijkstra                         | Run Dijkstra 3 times, combine paths            |       |
| [1857. Largest Color Value in a Directed Graph](https://leetcode.com/problems/largest-color-value-in-a-directed-graph/)                     | (Topological sort + Dijkstra-like relaxation) | Conceptual similarity, but on DAG              |       |
| [2699. Modify Graph Edge Weights](https://leetcode.com/problems/modify-graph-edge-weights/)                                                 | Dijkstra + dynamic edge update                | Adjust edges so shortest path matches target   |       |

---

## 🌍 **Bonus / Conceptual Crossovers**

| #                                                                                                        | Problem                                                                               | Related Concept           | Notes |
| -------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- | ------------------------- | ----- |
| [864. Shortest Path to Get All Keys](https://leetcode.com/problems/shortest-path-to-get-all-keys/)       | BFS with bitmask (can adapt to weighted Dijkstra)                                     | Each bitmask = new state  |       |
| [847. Shortest Path Visiting All Nodes](https://leetcode.com/problems/shortest-path-visiting-all-nodes/) | BFS/Bitmask variant of Dijkstra                                                       | Traveling Salesman flavor |       |
| [2866. Beautiful Towers II](https://leetcode.com/problems/beautiful-towers-ii/)                          | (Greedy / DP) not direct Dijkstra but helps in intuition of minimal cost accumulation |                           |       |

---

## 🧮 **Recommended Practice Order**

**🔹 Start Here (Core Implementation)**

1. 743. Network Delay Time
2. 1631. Path With Minimum Effort
3. 505. The Maze II

**🔹 Then Try State-Variants**
4. 787. Cheapest Flights Within K Stops
5. 1976. Number of Ways to Arrive at Destination
6. 2290. Minimum Obstacle Removal to Reach Corner

**🔹 Finally, Advance to Multi-Constraint Problems**
7. 499. The Maze III
8. 2203. Minimum Weighted Subgraph With Required Paths
9. 2662. Minimum Cost of a Path With Special Roads

---

## 🧠 **Tips While Practicing**

* Always use **`priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>`**.
* Store **distance** as the first element in heap to auto-sort by shortest distance.
* For grid problems, think of `(row, col)` as node indices.
* In multi-state problems, store `(dist, node, state)` tuples.
* Use **unordered_map / vector<vector<pair<int,int>>>** for adjacency list.

---


