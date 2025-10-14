`list` in C++ STL**, which is a **doubly linked list** — used in **frequent insertions/deletions in the middle, LRU cache, and custom data structures**.

---

# 🟢 C++ `list` STL Cheat Sheet

---

### 1️⃣ Basic Declaration

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> lst;            // empty list of integers
    list<int> lst2 = {1,2,3}; // initialize with values
}
```

**Notes:**

* Doubly linked list → each node has `prev` and `next`
* **Efficient insert/delete** anywhere (O(1) if iterator known)
* Does **not support random access** (`lst[i]` is invalid)

---

### 2️⃣ Core Operations

```cpp
list<int> lst;

lst.push_back(10);    // add at end
lst.push_front(5);    // add at front

cout << lst.front() << "\n"; // 5
cout << lst.back() << "\n";  // 10

lst.pop_front();      // remove front
lst.pop_back();       // remove back
```

* `push_front` / `push_back` → add
* `pop_front` / `pop_back` → remove
* `front()` / `back()` → access

---

### 3️⃣ Insert / Erase

```cpp
list<int> lst = {1,2,3,4};
auto it = lst.begin();
advance(it, 2);     // move iterator to position 3

lst.insert(it, 10); // insert 10 before 3rd element
lst.erase(it);      // erase element at iterator
```

* `insert(iterator, value)` → O(1)
* `erase(iterator)` → O(1)

---

### 4️⃣ Iterators

```cpp
for(auto it = lst.begin(); it != lst.end(); ++it)
    cout << *it << " ";

for(auto it = lst.rbegin(); it != lst.rend(); ++it)
    cout << *it << " ";
```

* Supports `begin(), end(), rbegin(), rend()`
* Range-based for loops:

```cpp
for(auto &x : lst) cout << x << " ";
```

---

### 5️⃣ Useful Functions

```cpp
lst.size();       // number of elements
lst.empty();      // check if empty
lst.sort();       // sort the list
lst.reverse();    // reverse the list
lst.unique();     // remove consecutive duplicates
lst.merge(lst2);  // merge two sorted lists
lst.clear();      // remove all elements
```

* Efficient **insertion, deletion, and splicing**
* `sort`, `merge`, `unique` only work efficiently with `list`

---

### 6️⃣ Common Use-Cases in Interviews

| Pattern                | Use Case                           |
| ---------------------- | ---------------------------------- |
| Frequent insert/delete | Middle of sequence                 |
| LRU Cache              | Maintain order of usage            |
| Sliding window / deque | Custom double-ended operations     |
| Sequence manipulation  | Sort, merge, reverse efficiently   |
| Linked list simulation | Implement custom linked structures |

---

### 7️⃣ Complexity

| Operation                | Complexity |
| ------------------------ | ---------- |
| push_front/back          | O(1)       |
| pop_front/back           | O(1)       |
| insert/erase at iterator | O(1)       |
| random access (`lst[i]`) | N/A        |
| size / empty             | O(1)       |

---

### ✅ Tips for Interviews

1. Use `list` when **frequent insert/delete in middle** is required
2. Prefer `vector` or `deque` if **random access needed**
3. Use **iterators** for traversal and modification
4. Combine with **map or unordered_map** for LRU cache

