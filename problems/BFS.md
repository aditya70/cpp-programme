### 🟢 **Beginner / Introductory BFS**

These are perfect to warm up and solidify BFS fundamentals.

| Problem                                                                                               | Topic                | Notes                                          |
| ----------------------------------------------------------------------------------------------------- | -------------------- | ---------------------------------------------- |
| [200. Number of Islands](https://leetcode.com/problems/number-of-islands/)                            | Grid BFS             | Classic flood fill (BFS or DFS both possible). |
| [695. Max Area of Island](https://leetcode.com/problems/max-area-of-island/)                          | Grid BFS             | Track connected components’ sizes.             |
| [542. 01 Matrix](https://leetcode.com/problems/01-matrix/)                                            | Multi-source BFS     | Start BFS from all 0s simultaneously.          |
| [994. Rotting Oranges](https://leetcode.com/problems/rotting-oranges/)                                | BFS with time layers | Each BFS level = 1 minute.                     |
| [1091. Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/) | BFS shortest path    | Diagonal moves allowed.                        |
| [733. Flood Fill](https://leetcode.com/problems/flood-fill/)                                          | BFS traversal        | Simple BFS/DFS grid traversal.                 |

---

### 🟡 **Intermediate BFS**

These build on core BFS and add **levels, states, or graph structure**.

| Problem                                                                          | Topic                | Notes                                        |
| -------------------------------------------------------------------------------- | -------------------- | -------------------------------------------- |
| [127. Word Ladder](https://leetcode.com/problems/word-ladder/)                   | BFS on words         | Classic shortest path in a word graph.       |
| [279. Perfect Squares](https://leetcode.com/problems/perfect-squares/)           | BFS on numbers       | Treat numbers as nodes and squares as edges. |
| [752. Open the Lock](https://leetcode.com/problems/open-the-lock/)               | BFS on states        | Avoid deadends, find shortest rotations.     |
| [310. Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees/) | BFS on tree          | Topological trim using BFS.                  |
| [909. Snakes and Ladders](https://leetcode.com/problems/snakes-and-ladders/)     | BFS on board         | 1D→2D mapping trick; shortest dice path.     |
| [207. Course Schedule](https://leetcode.com/problems/course-schedule/)           | BFS topological sort | Kahn’s algorithm (graph indegree BFS).       |
| [210. Course Schedule II](https://leetcode.com/problems/course-schedule-ii/)     | BFS topological sort | Same idea but return order.                  |

---

### 🔵 **Advanced BFS / Variations**

For when you’re comfortable with BFS on grids and graphs.

| Problem                                                                                                  | Topic                    | Notes                         |
| -------------------------------------------------------------------------------------------------------- | ------------------------ | ----------------------------- |
| [126. Word Ladder II](https://leetcode.com/problems/word-ladder-ii/)                                     | BFS + Backtracking       | Build paths using BFS + DFS.  |
| [815. Bus Routes](https://leetcode.com/problems/bus-routes/)                                             | BFS with graph of routes | Model buses as graph nodes.   |
| [847. Shortest Path Visiting All Nodes](https://leetcode.com/problems/shortest-path-visiting-all-nodes/) | BFS with bitmask         | State = (node, visited mask). |
| [864. Shortest Path to Get All Keys](https://leetcode.com/problems/shortest-path-to-get-all-keys/)       | BFS with state tracking  | State = (x, y, keys bitmask). |
| [934. Shortest Bridge](https://leetcode.com/problems/shortest-bridge/)                                   | Multi-step BFS           | Flood-fill + layer BFS.       |

---

### ⚡ **Bonus BFS Practice Tips**

* Try writing BFS both with **queue-based layer counting** and **distance arrays**.
* Visualize BFS levels to understand shortest paths intuitively.
* Practice identifying when to use **multi-source BFS** (e.g., 01 Matrix, Rotting Oranges).



##### Applications:

Shortest path in unweighted graphs
Track time/distance from source
Level order traversal in trees
Finding connected components
Example: Rotting oranges, shortest path, word ladder
Multi-source spreading (virus, fire, etc.)
1. Rotting Oranges (Multi-source layer BFS)
2. Shortest Path (Single-source layer BFS)


##### Flood Fill
Flood Fill is a computer graphics algorithm used to determine and fill a connected region with a specific color. It is similar to the "paint bucket" tool in image editing software. The algorithm starts from a seed point and recursively or iteratively fills all neighboring pixels (or nodes) that have the same initial color with a new color.

##### Common applications:
Finding connected components
Marking/coloring regions in a grid
Image editing
Maze solving
Region detection
Paint bucket tool in image editors, island counting


