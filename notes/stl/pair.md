`pair` in C++ STL is a **simple container to store two related values**. It’s heavily used in **graphs, DP, sorting, and priority queues**.

---

# 🟢 C++ `pair` STL Cheat Sheet

### 1️⃣ Basic Declaration

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<int,int> p1;              // default {0,0}
    pair<int,int> p2 = {10,20};    // initialize with values
    pair<string,int> p3 = {"Alice", 25};
    
    cout << p2.first << " " << p2.second << "\n"; // 10 20
}
```

* `first` → first element
* `second` → second element

---

### 2️⃣ Using `make_pair`

```cpp
pair<int,string> p;
p = make_pair(1, "Hello");

cout << p.first << " " << p.second << "\n"; // 1 Hello
```

* Often used when returning multiple values from a function

---

### 3️⃣ Pair in Vector / Array

```cpp
vector<pair<int,int>> v;
v.push_back({1,2});
v.push_back(make_pair(3,4));

for(auto &[x,y] : v)
    cout << x << "," << y << "\n";
```

* Useful for storing **edges in a graph** or **coordinate points**

---

### 4️⃣ Pair in Map / Set

```cpp
map<int,string> mp;
mp.insert({1,"One"});
mp[2] = "Two";

// Iterate using pair
for(auto &[key,val] : mp)
    cout << key << " -> " << val << "\n";
```

* Iterating map returns **pair<const key, value>**

---

### 5️⃣ Pair in Priority Queue

```cpp
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
pq.push({10,1}); // {distance, node}
pq.push({5,2});
pq.push({15,3});

while(!pq.empty()) {
    auto [d,node] = pq.top(); pq.pop();
    cout << node << " : " << d << "\n";
}
```

* Commonly used in **Dijkstra, Prim, BFS with weights**

---

### 6️⃣ Pair Comparison

```cpp
pair<int,int> a = {1,5};
pair<int,int> b = {1,10};

cout << (a < b) << "\n"; // 1 (true)
```

* `pair` is compared **lexicographically**: first element first, then second
* Useful in sorting vectors of pairs

---

### ✅ Tips for Interviews

1. Use **structured bindings** (C++17): `auto &[x,y] = p;`
2. Great for **graph edges**, `(weight, node)` pairs, coordinates
3. Can be **nested**: `pair<int,pair<int,int>>` for advanced problems
4. Can be sorted automatically in **vectors / arrays** due to lexicographical comparison


