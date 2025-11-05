Sure! Let’s make this super clear 👇

---

# ✅ What is Topological Sort?

Topological Sort is a **linear ordering of vertices** in a **Directed Acyclic Graph (DAG)** such that:

➡️ For every directed edge `u -> v`,
✅ **`u` comes before `v` in the ordering**

### 📌 When is it used?

Whenever you have ordering dependencies:

| Real-world example         | Explanation                           |
| -------------------------- | ------------------------------------- |
| Course prerequisites       | Take Course A before B                |
| Task scheduling            | A task must finish before next starts |
| Build systems              | Lib1 builds before App                |
| Package installation order | Install dependencies first            |

📍 It only works on DAG (no cycles allowed).
If there's a cycle → **no valid topological ordering exists** ✅

---

# 🧠 How does it work?

### Kahn’s Algorithm (Using BFS + In-degree)

1️⃣ Compute in-degree for each node
(in-degree = number of incoming edges)

2️⃣ Push all nodes with in-degree `0` into queue
(These have no dependency)

3️⃣ Pop from queue → add to result

4️⃣ For each outgoing edge `u → v`
decrement `inDegree[v]`
if it becomes `0` → push into queue

5️⃣ Continue until queue is empty

6️⃣ If result size < total nodes → Graph has cycle ❌

---

# ✅ C++ Code (Topological Sort using BFS)

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);

    // Compute indegree
    for (int i = 0; i < n; i++) {
        for (int v : adj[i]) {
            indegree[v]++;
        }
    }

    queue<int> q;
    // Push nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);

        // Reduce indegree of neighbors
        for (int v : adj[u]) {
            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Check if cycle exists
    if (order.size() != n) {
        cout << "Graph has a cycle, no topological order exists.\n";
        return {};
    }

    return order;
}

int main() {
    int n = 6; // 6 nodes: 0 to 5
    vector<vector<int>> adj = {
        {2, 3}, // 0 -> {2,3}
        {3, 4}, // 1 -> {3,4}
        {3},    // 2 -> {3}
        {5},    // 3 -> {5}
        {5},    // 4 -> {5}
        {}      // 5 -> {}
    };

    vector<int> result = topoSort(n, adj);

    cout << "Topological Order: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
```

---

### ✅ Sample Output

```
Topological Order: 0 1 2 4 3 5
```

*(Order may vary as long as dependency constraints are satisfied)*

---

# 🧩 Complexity

| Metric | Value    |
| ------ | -------- |
| Time   | O(V + E) |
| Space  | O(V + E) |

Very efficient for DAG problems ✅

---

# ⚠️ When Unique Topological Sort Exists?

If at any BFS step `queue.size() > 1`
➡️ More than one ordering is possible
➡️ Topological sort is **not unique**

Used in problems like:

✅ **Sequence Reconstruction (LeetCode 444)**
✅ **Alien Dictionary (LeetCode 269)**

---


---

# ✅ Topological Sort using DFS

### 🧠 Idea

* DFS explores nodes deeply.
* After visiting all neighbors of a node, **push node into stack**.
* Reverse the stack → **Topological Order** ✅

Why?
Because we ensure all dependencies (`u → v`) are processed *before* adding `u` to the ordering.

---

# ✅ C++ Code (DFS Approach)

```cpp
#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited, st);
        }
    }
    st.push(u);  // Add after exploring neighbors
}

vector<int> topoSortDFS(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    vector<int> order;
    while (!st.empty()) {
        order.push_back(st.top());
        st.pop();
    }
    return order;  // Topological Order
}

int main() {
    int n = 6;
    vector<vector<int>> adj = {
        {2, 3}, // 0 -> {2,3}
        {3, 4}, // 1 -> {3,4}
        {3},    // 2 -> {3}
        {5},    // 3 -> {5}
        {5},    // 4 -> {5}
        {}      // 5
    };

    vector<int> result = topoSortDFS(n, adj);

    cout << "Topological Order (DFS): ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
```

---

### ✅ Output

```
Topological Order (DFS): 1 4 0 2 3 5
```

(Order may differ but remains valid)

---

# ⚠️ Cycle Detection (Important for Interviews)

DFS version needs an extra check to detect **cycles** (otherwise graph isn’t a DAG → no topological ordering).

We maintain:

* `0 = unvisited`
* `1 = visiting (in recursion stack)`
* `2 = visited`

If we revisit a `visiting` node → **cycle found**

✅ Code with cycle detection:

```cpp
bool dfsCycle(int u, vector<vector<int>>& adj, vector<int>& state, stack<int>& st) {
    state[u] = 1; // visiting
    for (int v : adj[u]) {
        if (state[v] == 1) return true; // cycle found
        if (state[v] == 0 && dfsCycle(v, adj, state, st)) return true;
    }
    state[u] = 2; // fully visited
    st.push(u);
    return false;
}

vector<int> topoSortDFS_CycleCheck(int n, vector<vector<int>>& adj) {
    vector<int> state(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (state[i] == 0) {
            if (dfsCycle(i, adj, state, st)) {
                cout << "Cycle detected!" << endl;
                return {};
            }
        }
    }

    vector<int> order;
    while (!st.empty()) {
        order.push_back(st.top());
        st.pop();
    }
    return order;
}
```

---

# ✅ BFS vs DFS Topological Sort

| Feature                   | BFS (Kahn’s Algorithm)       | DFS Approach                |
| ------------------------- | ---------------------------- | --------------------------- |
| Detect cycle              | Yes                          | Must add logic              |
| Unique ordering detection | Easy (`queue.size()>1`)      | Hard                        |
| Order stability           | More predictable             | May vary by DFS order       |
| Use case                  | Scheduling, uniqueness check | Stack-based uses, DP on DAG |

✅ For LeetCode 444 (Sequence Reconstruction), BFS is better because **uniqueness** matters.

---


