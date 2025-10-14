`queue` in C++ STL**, which is a **FIFO (First-In-First-Out) container adapter** — frequently used in **BFS, sliding window, order processing, level-order traversal**, and many interview problems.

---

# 🟢 C++ `queue` STL Cheat Sheet

---

### 1️⃣ Basic Declaration

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;          // empty queue of integers
}
```

**Notes:**

* `queue` is a **container adapter**, usually backed by `deque`.
* Supports **FIFO operations**: push, pop, front, back.

---

### 2️⃣ Core Operations

```cpp
queue<int> q;

q.push(10);    // add to back
q.push(20);
q.push(30);

cout << q.front() << "\n";  // 10
cout << q.back() << "\n";   // 30

q.pop();                     // remove front element
cout << q.front() << "\n";   // 20

cout << q.size() << "\n";    // 2
cout << q.empty() << "\n";   // false
```

* `front()` → returns front element
* `back()` → returns last element
* `push(x)` → adds element at back
* `pop()` → removes front element

---

### 3️⃣ Queue of Pairs / Objects

```cpp
queue<pair<int,int>> q;
q.push({1,100});
q.push({2,200});

auto [a,b] = q.front(); q.pop();
cout << a << " " << b << "\n"; // 1 100
```

* Can store **pairs, tuples, or objects**

---

### 4️⃣ Iterating Through Queue

`queue` **does not provide iterators directly**, but you can loop with `pop`:

```cpp
queue<int> q;
q.push(10); q.push(20); q.push(30);

while(!q.empty()) {
    cout << q.front() << " ";
    q.pop();
}
// Output: 10 20 30
```

* Access is **FIFO only**

---

### 5️⃣ Common Use-Cases in Interviews

| Pattern               | Use Case                         |
| --------------------- | -------------------------------- |
| BFS (graph/tree)      | Queue to store nodes             |
| Sliding window        | Maintain current window elements |
| Level-order traversal | Use queue for each level         |
| Order processing      | Tasks/events in order            |
| Multistage processes  | Simulate step-by-step processing |

---

### 6️⃣ Complexity

| Operation | Complexity |
| --------- | ---------- |
| `push`    | O(1)       |
| `pop`     | O(1)       |
| `front`   | O(1)       |
| `back`    | O(1)       |
| `size`    | O(1)       |
| `empty`   | O(1)       |

---

### ✅ Tips for Interviews

1. **Queue = FIFO**, stack = LIFO — remember clearly.
2. For BFS, store **pairs or tuples**: `(node, distance)` or `(x, y, steps)`.
3. Combine with **priority_queue** if you need **weighted BFS / Dijkstra**.
4. Use **deque** if you need **double-ended queue operations** (`push_front`, `push_back`) — useful for sliding window max/min.


