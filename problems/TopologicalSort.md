
# 📘 Topological Sort Mastery Plan

We’ll go through **increasing difficulty** with the exact pattern needed:

| Level                              | Problem                 | Key Concept               |
| ---------------------------------- | ----------------------- | ------------------------- |
| 1️⃣ Basic                          | Course Schedule I       | Cycle detection           |
| 2️⃣ Ordering Output                | Course Schedule II      | Actual topo order         |
| 3️⃣ Dependency uniqueness          | Sequence Reconstruction | Uniqueness check          |
| 4️⃣ Ordering with unknown alphabet | Alien Dictionary        | Lexicographic constraints |
| 5️⃣ Longest path in DAG            | Longest Path in DAG     | DP layered on top of topo |
| 6️⃣ Team hierarchy                 | Sort Items by Groups    | Multi-layer graph         |
| 7️⃣ Event ordering                 | Minimum Height Trees    | Reverse root dependency   |

---

## ✅ Solve in this order

### ✅ 1️⃣ Course Schedule I

🎯 Detect if DAG or not
🔗 [https://leetcode.com/problems/course-schedule/](https://leetcode.com/problems/course-schedule/)

➡️ Use BFS (Kahn) or DFS cycle detection

---

### ✅ 2️⃣ Course Schedule II

🎯 Return actual topological ordering
🔗 [https://leetcode.com/problems/course-schedule-ii/](https://leetcode.com/problems/course-schedule-ii/)

➡️ Same implementation as BFS topological sort

---

### ✅ 3️⃣ Sequence Reconstruction

🎯 Uniqueness of topological ordering
🔗 [https://leetcode.com/problems/sequence-reconstruction/](https://leetcode.com/problems/sequence-reconstruction/)

➡️ Verify queue always size == 1
➡️ Verify matches given sequence

---

### ✅ 4️⃣ Alien Dictionary

🎯 Build graph from pairwise constraints + topo sort
🔗 [https://leetcode.com/problems/alien-dictionary/](https://leetcode.com/problems/alien-dictionary/)

➡️ Uniqueness also matters
➡️ Lexicographic characters instead of numbers

---

### ✅ 5️⃣ Longest Path in DAG

🎯 DP with topological ordering
🔗 [https://cses.fi/problemset/task/1671/](https://cses.fi/problemset/task/1671/) (or similar DAG longest path problem)

➡️ After topo: Relax edges in topo order

---

### ✅ 6️⃣ Sort Items by Groups (Very Important!)

🎯 Graph over groups + graph over items
🔗 [https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/](https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/)

➡️ Nested topo: first on groups, then inside group

---

### ✅ 7️⃣ Minimum Height Trees

🎯 Reverse-dependency pruning
🔗 [https://leetcode.com/problems/minimum-height-trees/](https://leetcode.com/problems/minimum-height-trees/)

➡️ Leaf pruning = reverse topo concept

---

# ✅ Universal C++ Templates

## 🎯 1️⃣ BFS-Based Topological Sort Template

```cpp
vector<int> topologicalSort(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
        for (int v : adj[i])
            indegree[v]++;
    
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u])
            if (--indegree[v] == 0)
                q.push(v);
    }

    if (topo.size() < n) {
        cout << "Cycle detected!\n";
        return {};
    }
    return topo;
}
```

---

## 🎯 2️⃣ DFS-Based Topological Sort Template

```cpp
bool dfsTopo(int u, vector<vector<int>>& adj,
             vector<int>& state, stack<int>& st) {
    state[u] = 1; // visiting

    for (int v : adj[u]) {
        if (state[v] == 1) return true; // cycle
        if (state[v] == 0 && dfsTopo(v, adj, state, st))
            return true;
    }

    state[u] = 2;
    st.push(u);
    return false;
}

vector<int> topologicalSortDFS(int n, vector<vector<int>>& adj) {
    vector<int> state(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++)
        if (state[i] == 0)
            if (dfsTopo(i, adj, state, st))
                return {}; // cycle

    vector<int> order;
    while (!st.empty())
        order.push_back(st.top()), st.pop();

    return order;
}
```

---

# 🎯 Important Interview Notes

| Concept                   | Checked by Problem                         |
| ------------------------- | ------------------------------------------ |
| Cycle detection           | CS1 / CS2 / MHT (reverse)                  |
| Unique ordering           | Sequence Reconstruction / Alien Dictionary |
| Graph building complexity | Alien Dictionary                           |
| Multi-graph dependency    | Sort Items by Groups                       |
| DP on topo                | Longest path in DAG                        |

---



