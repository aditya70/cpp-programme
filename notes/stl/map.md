`map` in C++ STL**, one of the most versatile containers for **associative storage** — used extensively in coding interviews and competitive programming.

---

# 🟢 C++ `map` STL Cheat Sheet

### 1️⃣ Basic Declaration

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, string> mp;           // key -> value
    map<string, int> mp2;

    mp[1] = "One";                 // insert / update
    mp[2] = "Two";

    mp.insert({3, "Three"});       // alternative insert
}
```

**Notes:**

* Keys are **unique and ordered** (by default ascending).
* Internally implemented as **Red-Black Tree** → O(log n) operations.

---

### 2️⃣ Access Elements

```cpp
cout << mp[1] << "\n";      // "One"
cout << mp.at(2) << "\n";   // "Two"
// cout << mp.at(5);        // throws exception if key doesn't exist

// check existence
if (mp.count(3)) cout << "Key exists\n"; 
```

* `mp[key]` → inserts default if key not found
* `mp.at(key)` → throws exception if key not found
* `count(key)` → returns 0 or 1

---

### 3️⃣ Iterators

```cpp
for(auto it = mp.begin(); it != mp.end(); ++it)
    cout << it->first << " : " << it->second << "\n";

// range-based for
for(auto &[k,v] : mp)
    cout << k << " : " << v << "\n";
```

* `begin(), end(), rbegin(), rend()`
* Supports **structured bindings** (C++17): `auto &[key,value]`

---

### 4️⃣ Erase / Clear

```cpp
mp.erase(2);               // erase by key
auto it = mp.find(3);
if(it != mp.end()) mp.erase(it); // erase by iterator
mp.clear();                // remove all
```

* `erase(key)` → O(log n)
* `erase(iterator)` → O(1)

---

### 5️⃣ Lower Bound / Upper Bound

```cpp
map<int,string> mp = {{1,"A"}, {3,"B"}, {5,"C"}};

auto it = mp.lower_bound(2); // first key >= 2 → 3
auto it2 = mp.upper_bound(3); // first key > 3 → 5

cout << it->first << "\n";  // 3
cout << it2->first << "\n"; // 5
```

* Useful in **range queries** and **binary search on keys**

---

### 6️⃣ Multimap (Duplicate Keys)

```cpp
multimap<int,string> mmp;
mmp.insert({1,"A"});
mmp.insert({1,"B"}); // allows duplicate keys

for(auto &[k,v] : mmp) cout << k << " : " << v << "\n";
```

* Use **multimap** when keys can repeat
* Ordered like `map`

---

### 7️⃣ Unordered Map (Hash Map)

```cpp
unordered_map<int,string> ump;
ump[1] = "One";
ump[2] = "Two";

// O(1) average, O(n) worst-case
```

* **No ordering**, faster than `map`
* Keys must be **hashable**

---

### 8️⃣ Common Patterns / Tricks

| Pattern                  | Use Case                        |
| ------------------------ | ------------------------------- |
| Counting frequency       | `map<int,int> freq; freq[x]++;` |
| Grouping elements        | `map<string,vector<int>>`       |
| Top-K / Priority         | `map<int,priority_queue<int>>`  |
| Range queries            | `lower_bound`, `upper_bound`    |
| Dynamic programming memo | `map<pair<int,int>,int>`        |

---

### 9️⃣ Complexity

| Operation | Map      | Unordered Map        |
| --------- | -------- | -------------------- |
| Insert    | O(log n) | O(1) avg, O(n) worst |
| Find      | O(log n) | O(1) avg, O(n) worst |
| Erase     | O(log n) | O(1) avg, O(n) worst |
| Access    | O(log n) | O(1) avg             |

---

✅ **Tips for Interviews**

1. Prefer **`unordered_map`** if **ordering doesn’t matter** → faster.
2. Use **structured bindings** to simplify loops.
3. `map` keys are always sorted → use `lower_bound`/`upper_bound`.
4. For **counting frequency** → `freq[x]++` is super concise.

```
The count() function for unordered_map returns 0 or 1.
unordered_map<int, int> map;
map[5] = 100;
map[10] = 200;

int result1 = map.count(5);   // Returns 1 (key exists)
int result2 = map.count(10);  // Returns 1 (key exists)
int result3 = map.count(99);  // Returns 0 (key doesn't exist)
```