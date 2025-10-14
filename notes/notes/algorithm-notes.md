```
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
```

### DFS with Cycle Detection
- State 0 = unvisited
- State 1 = visiting (in the current recursion stack)
- State 2 = visited (fully processed, no cycle found in its descendants)

#### Algorithm:
- Build adjacency list.
- For each node (course) i from 0 to n-1, if unvisited, start DFS:
    - If during DFS you reach a node that is visiting, you found a cycle → return false.
    - Once all children are processed, mark node as visited.

###. Topological Sort / Kahn’s Algorithm (BFS + In-Degree)

Another way: if you can topologically sort the graph, there’s no cycle; otherwise, there is.

Algorithm:

Compute in-degree of each node (number of prerequisites).

Build adjacency list graph[b] contains a if b → a.

Initialize queue with all nodes whose in-degree is 0 (courses you can take immediately).

While queue isn’t empty:

Pop a course u from queue.

For each neighbor v in graph[u]:

Decrease in-degree[v] by 1.

If in-degree[v] becomes 0, push v into queue.

Keep count of how many courses you processed.

If processed count == numCourses, you can finish; otherwise, there was a cycle → return false.