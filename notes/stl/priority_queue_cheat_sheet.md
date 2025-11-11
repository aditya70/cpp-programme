# 🟢 C++ `priority_queue` Cheat Sheet

### 1️⃣ Basic Syntax

```cpp
#include <bits/stdc++.h>
using namespace std;

// Max-heap (default)
priority_queue<int> pq;
pq.push(10);
pq.push(5);
pq.push(20);
cout << pq.top() << "\n"; // 20
pq.pop();
cout << pq.top() << "\n"; // 10
```

* **Default:** Max-heap
* `top()` → get top element
* `pop()` → remove top element
* `push(x)` → insert element

---

### 2️⃣ Min-Heap

```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
minHeap.push(10);
minHeap.push(5);
minHeap.push(20);

cout << minHeap.top() << "\n"; // 5
```

---

### 3️⃣ Priority Queue of Pairs

**Min-heap by first element** (common in Dijkstra / Prim):

```cpp
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
pq.push({2, 100}); // {weight, node}
pq.push({1, 200});
pq.push({5, 50});

auto [w, node] = pq.top(); pq.pop();
```

* `greater<pair<int,int>>` → min-heap by **first element**
* Use for `(weight, node)` patterns

---

### 4️⃣ Custom Comparator for Struct / Class

```cpp
struct Node {
    int val, priority;
    bool operator<(const Node &other) const {
        return priority > other.priority; // smaller priority = higher
    }
};

TL;DR:
Always define operator> (or <) when using a custom struct inside priority_queue with greater<> or less<>.

priority_queue<Node> pq;
pq.push({10,3});
pq.push({20,1});
pq.push({30,2});
```

* Smallest priority comes out first
* Can also use **lambda**:

```cpp
auto cmp = [](pair<int,int> &a, pair<int,int> &b){ return a.second > b.second; };
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
```

---

### 5️⃣ Priority Queue of Vectors / Tuples

```cpp
priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
pq.push({dist, u, v});
auto [d, u, v] = pq.top(); pq.pop();
```

* Useful for multi-value comparison (distance + node + extra info)

---

### 6️⃣ Common Patterns / Tricks

| Pattern                     | Example                                         |
| --------------------------- | ----------------------------------------------- |
| **K largest elements**      | Min-heap of size K                              |
| **K smallest elements**     | Max-heap of size K                              |
| **Sliding Window Max/Min**  | Heap + index check                              |
| **Weighted BFS / Dijkstra** | `priority_queue<pair<int,int>, ..., greater<>>` |
| **Prim’s MST**              | Same as Dijkstra, node + weight                 |

---

### 7️⃣ Complexity

| Operation | Complexity |
| --------- | ---------- |
| `push`    | O(log n)   |
| `pop`     | O(log n)   |
| `top`     | O(1)       |
| `size`    | O(1)       |

---

✅ **Tips for Interviews**

1. Always clarify: **max-heap or min-heap**.
2. For **pairs/tuples**, use `greater<>()` for min-heap.
3. Use **lambda or operator<** for custom sorting.
4. For **top-K problems**, size-bounded min/max heap works perfectly.


