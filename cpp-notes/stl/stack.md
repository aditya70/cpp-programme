`stack` in C++ STL**, which is a **LIFO (Last-In-First-Out) container adapter** — frequently used in **DFS, expression evaluation, undo operations, parentheses matching**, and many other interview problems.

---

# 🟢 C++ `stack` STL Cheat Sheet

---

### 1️⃣ Basic Declaration

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;          // empty stack of integers
}
```

**Notes:**

* `stack` is a **container adapter**, usually backed by `vector` or `deque`.
* Supports only **LIFO operations**: push, pop, top.

---

### 2️⃣ Core Operations

```cpp
stack<int> st;

st.push(10);    // add to top
st.push(20);
st.push(30);

cout << st.top() << "\n";  // 30
st.pop();                   // remove top element
cout << st.top() << "\n";  // 20

cout << st.size() << "\n";  // 2
cout << st.empty() << "\n"; // false
```

* `top()` → returns top element
* `pop()` → removes top element (no return)
* `push(x)` → adds element at top
* `size()` → number of elements
* `empty()` → check if stack is empty

---

### 3️⃣ Stack of Pairs / Objects

```cpp
stack<pair<int,int>> st;
st.push({1,100});
st.push({2,200});

auto [a,b] = st.top(); st.pop();
cout << a << " " << b << "\n"; // 2 200
```

* Can store **pairs, tuples, or objects**

---

### 4️⃣ Iterating Through Stack

`stack` **does not provide iterators directly**, but you can copy or use a loop with `pop`:

```cpp
stack<int> st = {10,20,30};
while(!st.empty()) {
    cout << st.top() << " ";
    st.pop();
}
// Output: 30 20 10
```

* Access is **LIFO only**

---

### 5️⃣ Common Use-Cases in Interviews

| Pattern                | Use Case                       |
| ---------------------- | ------------------------------ |
| DFS (graph/tree)       | Stack to store nodes           |
| Parentheses matching   | Check valid brackets           |
| Reverse a container    | Push all → pop into new vector |
| Expression evaluation  | Postfix / Infix / Prefix       |
| Undo / Redo operations | Maintain previous states       |

---

### 6️⃣ Complexity

| Operation | Complexity |
| --------- | ---------- |
| `push`    | O(1)       |
| `pop`     | O(1)       |
| `top`     | O(1)       |
| `size`    | O(1)       |
| `empty`   | O(1)       |

---

### ✅ Tips for Interviews

1. **Stack = LIFO**, queue = FIFO — remember this clearly.
2. Can be **implemented with vector, deque, or list**, STL default is fine.
3. For **iterating without modifying**, consider **copying the stack**.
4. Combine with **pair/tuple** for advanced DFS/BFS / DP problems.
