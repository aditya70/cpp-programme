`priority_queue` in C++**, which is a super useful STL container for **heap-based operations** (max-heap/min-heap) — often used in **Dijkstra, Prim, BFS variations, top-K problems**, etc.

---

## 1️⃣ Basic `priority_queue` Syntax

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Max-heap (default)
    priority_queue<int> pq;
    pq.push(10);
    pq.push(5);
    pq.push(20);

    cout << pq.top() << "\n"; // 20 (largest element)
    pq.pop();
    cout << pq.top() << "\n"; // 10
}
```

**Notes:**

* `top()` → returns largest element (by default)
* `pop()` → removes top element
* `push(x)` → adds element x
* Default is **max-heap**.

---

## 2️⃣ Min-Heap

C++ `priority_queue` is **max-heap by default**. To make it a **min-heap**:

```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
minHeap.push(10);
minHeap.push(5);
minHeap.push(20);

cout << minHeap.top() << "\n"; // 5
minHeap.pop();
cout << minHeap.top() << "\n"; // 10
```

---

## 3️⃣ Priority Queue of Pairs

Useful for **Dijkstra, Prim, BFS on weighted graphs**:

```cpp
// min-heap based on first element of pair
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
pq.push({2, 100}); // {weight, node}
pq.push({1, 200});
pq.push({5, 50});

while (!pq.empty()) {
    auto [w, node] = pq.top(); pq.pop();
    cout << "Node: " << node << ", Weight: " << w << "\n";
}
```

Output:

```
Node: 200, Weight: 1
Node: 100, Weight: 2
Node: 50, Weight: 5
```

✅ Notice how `greater<pair<int,int>>` makes it a **min-heap** based on the **first element of the pair**.

---

## 4️⃣ Custom Comparator

If you want to heap based on **custom rules**:

```cpp
struct Node {
    int val;
    int priority;
    bool operator<(const Node &other) const {
        return priority > other.priority; // smaller priority = higher priority
    }
};

int main() {
    priority_queue<Node> pq;
    pq.push({10, 3});
    pq.push({20, 1});
    pq.push({30, 2});

    while (!pq.empty()) {
        Node n = pq.top(); pq.pop();
        cout << "Val: " << n.val << ", Priority: " << n.priority << "\n";
    }
}
```

Output:

```
Val: 20, Priority: 1
Val: 30, Priority: 2
Val: 10, Priority: 3
```

---

## 5️⃣ Common Use-Cases in Interviews

| Problem Type   | Use Case                                      |
| -------------- | --------------------------------------------- |
| Graph          | Dijkstra’s shortest path, Prim’s MST          |
| Heap / Top-K   | K largest/smallest elements, streaming median |
| BFS / Variants | BFS with priority (like “weighted BFS”)       |
| Sliding Window | Sliding window max/min (with heap)            |

---

## 6️⃣ Tips / Tricks

* `priority_queue<int>` → max-heap
* `priority_queue<int, vector<int>, greater<int>>` → min-heap
* For **pair**, first element is default for comparison.
* For **custom class**, define `operator<` or lambda comparator.
* **Time Complexity:**

  * `push` → O(log n)
  * `pop` → O(log n)
  * `top` → O(1)

---

If you want, I can make a **one-page C++ `priority_queue` cheat sheet** including **min/max heap, pair, vector, custom comparator, and common tricks** for interviews.

Do you want me to do that?
