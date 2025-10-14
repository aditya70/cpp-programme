Absolutely! Let’s go **deep into `vector` in C++ STL**, which is one of the most important containers — widely used in interviews and competitive programming.

---

# 🟢 C++ `vector` STL Cheat Sheet

### 1️⃣ Basic Declaration

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;           // empty vector
    vector<int> v2(5);       // 5 elements initialized to 0
    vector<int> v3(5, 10);   // 5 elements initialized to 10
    vector<int> v4 = {1,2,3,4,5}; // initializer list
}
```

---

### 2️⃣ Access Elements

```cpp
vector<int> v = {10,20,30};

cout << v[0] << "\n";       // 10
cout << v.at(1) << "\n";    // 20 (bounds-checked)
cout << v.front() << "\n";  // 10
cout << v.back() << "\n";   // 30
```

* `v[i]` → no bounds check
* `v.at(i)` → throws `out_of_range` if invalid

---

### 3️⃣ Adding / Removing Elements

```cpp
vector<int> v;

v.push_back(10);   // add at end
v.emplace_back(20); // construct in-place

v.pop_back();      // remove last element

v.insert(v.begin()+1, 15);    // insert at position
v.erase(v.begin()+1);          // erase at position
v.clear();                     // remove all
```

* `insert` and `erase` **O(n)** in worst case
* `push_back` / `pop_back` **O(1) amortized**

---

### 4️⃣ Size / Capacity

```cpp
vector<int> v = {1,2,3};

cout << v.size() << "\n";      // 3
cout << v.capacity() << "\n";  // allocated memory
cout << v.empty() << "\n";     // false

v.reserve(100);  // preallocate memory
v.shrink_to_fit(); // reduce capacity to size
```

* `size()` → number of elements
* `capacity()` → allocated memory, may be larger than size

---

### 5️⃣ Iterators

```cpp
vector<int> v = {1,2,3,4,5};

// forward iterator
for(auto it = v.begin(); it != v.end(); ++it)
    cout << *it << " ";

// reverse iterator
for(auto it = v.rbegin(); it != v.rend(); ++it)
    cout << *it << " ";
```

* `begin(), end(), rbegin(), rend()`
* Can also use **range-based for**:

```cpp
for(auto x : v) cout << x << " ";
```

* Or with **reference** to modify:

```cpp
for(auto &x : v) x += 5;
```

---

### 6️⃣ Sorting / Algorithms

```cpp
vector<int> v = {4,1,3,5,2};

sort(v.begin(), v.end());              // ascending
sort(v.rbegin(), v.rend());            // descending
reverse(v.begin(), v.end());           // reverse
auto it = find(v.begin(), v.end(), 3); // find element
v.erase(it);                           // remove first occurrence
```

* Works with all STL algorithms: `count, lower_bound, upper_bound, binary_search`

---

### 7️⃣ 2D Vector (Matrix)

```cpp
vector<vector<int>> mat(3, vector<int>(4, 0)); // 3x4 matrix, all 0

mat[1][2] = 5;

for(auto &row : mat) {
    for(auto &x : row) cout << x << " ";
    cout << "\n";
}
```

* Common in **DP, graph adjacency lists**

---

### 8️⃣ Tricks / Tips

* **Pass by reference** to avoid copy: `void func(vector<int> &v)`
* Use `emplace_back` when constructing objects in-place
* For **dynamic 2D graphs**, use `vector<vector<pair<int,int>>> adj(n);`
* Preallocate with `reserve()` to avoid repeated reallocations


