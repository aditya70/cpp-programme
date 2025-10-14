`set` in C++ STL**, which is a **key container for unique, ordered elements** — heavily used in coding interviews and competitive programming.

---

# 🟢 C++ `set` STL Cheat Sheet

---

### 1️⃣ Basic Declaration

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;            // empty set of integers
    set<int> s2 = {1,2,3}; // initialize with values
}
```

**Notes:**

* Stores **unique elements**
* Elements are **sorted in ascending order** by default
* Implemented using **Red-Black Tree** → O(log n) operations

---

### 2️⃣ Insert / Erase / Find

```cpp
s.insert(10);
s.insert(5);
s.insert(20);

s.erase(5);          // remove 5
auto it = s.find(10); // returns iterator to element or s.end()
if (it != s.end()) cout << "Found 10\n";
```

* `insert(x)` → adds element
* `erase(x)` → remove element
* `find(x)` → iterator to element
* `count(x)` → 0 or 1

---

### 3️⃣ Iterators

```cpp
for(auto it = s.begin(); it != s.end(); ++it)
    cout << *it << " ";
cout << "\n";

// Reverse order
for(auto it = s.rbegin(); it != s.rend(); ++it)
    cout << *it << " ";
```

* C++17 structured binding not needed for single values: `auto &x` works

---

### 4️⃣ Lower Bound / Upper Bound

```cpp
set<int> s = {1,3,5,7,9};

auto it1 = s.lower_bound(4); // first element >= 4 → 5
auto it2 = s.upper_bound(5); // first element > 5 → 7

cout << *it1 << " " << *it2 << "\n"; // 5 7
```

* **Useful in range queries** and closest element problems

---

### 5️⃣ Multiset (Duplicates Allowed)

```cpp
multiset<int> ms;
ms.insert(10);
ms.insert(10); // allowed
ms.insert(5);

cout << ms.count(10) << "\n"; // 2
```

* `multiset` allows **duplicate elements**
* Still **sorted automatically**

---

### 6️⃣ Unordered Set (Hash Set)

```cpp
unordered_set<int> us;
us.insert(10);
us.insert(5);

// average O(1) operations
```

* **No order**, faster than `set`
* Keys must be **hashable**

---

### 7️⃣ Common Patterns / Tricks

| Pattern                 | Use Case                               |
| ----------------------- | -------------------------------------- |
| Unique collection       | remove duplicates from array/vector    |
| Closest element         | `lower_bound` / `upper_bound`          |
| Counting frequency      | use `multiset`                         |
| Sliding window problems | `set` or `multiset` for window min/max |
| Dynamic programming     | store states efficiently               |

---

### 8️⃣ Complexity

| Operation             | `set`    | `unordered_set`      |
| --------------------- | -------- | -------------------- |
| Insert                | O(log n) | O(1) avg, O(n) worst |
| Find                  | O(log n) | O(1) avg, O(n) worst |
| Erase                 | O(log n) | O(1) avg, O(n) worst |
| Access sorted element | O(log n) | N/A                  |

---

### ✅ Tips for Interviews

1. Use **`set`** if you need **sorted unique elements**.
2. Use **`unordered_set`** for **fast lookup** if order is not needed.
3. `multiset` is great for **sliding window min/max** or **frequency counting**.
4. Combine with **iterators, lower_bound/upper_bound** for closest element queries.

---

If you want, I can also make a **one-page STL `set` cheat sheet** with:

* `set`, `multiset`, `unordered_set`
* Key functions and iterators
* Common interview patterns and tricks

