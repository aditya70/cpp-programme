# 🟢 C++ Comparator Cheat Sheet (Generic)

In C++, **comparators** define **custom rules for sorting or ordering** in STL containers like `sort`, `priority_queue`, `set`, `map`, etc.

---

## 1️⃣ **Comparator Basics**

A **comparator** is a **function or functor** that returns:

* `true` → first element should come **before** second
* `false` → otherwise

Used in:

* `sort()`
* `priority_queue`
* `set`, `map` (custom ordering)

---

## 2️⃣ **Using Function Pointer**

```cpp
#include <bits/stdc++.h>
using namespace std;

// Comparator for descending order
// Custom comparator with any name  eg- myComparator. bool myComparator(int a, int b) { return a > b; // descending }
bool cmp(int a, int b) {
    return a > b; // descending
}

int main() {
    vector<int> v = {1,4,2,5,3};
    sort(v.begin(), v.end(), cmp); // sort using custom comparator // function pointer
    
    for(int x : v) cout << x << " "; // 5 4 3 2 1
}
```

* `sort(begin, end, cmp)` → `cmp(a,b) = true` if `a` comes **before b**

---

## 3️⃣ **Lambda Function Comparator** (Modern C++)

```cpp
vector<int> v = {1,4,2,5,3};

// ascending
sort(v.begin(), v.end(), [](int a,int b){ return a<b; }); // with lambda

// descending
sort(v.begin(), v.end(), [](int a,int b){ return a>b; });
```

* No need to write separate function
* Very useful for **short, inline comparators**

---

## 4️⃣ **Comparator for Structs / Classes**

```cpp
struct Student {
    string name;
    int marks;
};

// Sort by marks descending
bool cmp(Student a, Student b) {
    return a.marks > b.marks;
}

int main() {
    vector<Student> v = {{"Alice",90},{"Bob",85},{"Charlie",95}};
    sort(v.begin(), v.end(), cmp);
    
    for(auto s : v) cout << s.name << " " << s.marks << "\n";
}
```

* Can also use **lambda**:

```cpp
sort(v.begin(), v.end(), [](Student a, Student b){ return a.marks > b.marks; });
```

---

## 5️⃣ **Comparator in Priority Queue**

```cpp
// Min-heap for integers
priority_queue<int, vector<int>, greater<int>> pq;

// Functor / Struct (name is for type only)
// Custom comparator for struct
struct cmp {
    // operator name is fixed
    bool operator()(Student a, Student b) {
        return a.marks < b.marks; // max-heap by marks
    }
};

priority_queue<Student, vector<Student>, cmp> pq2;
```

* `priority_queue<Type, Container, Comparator>`

---

## 6️⃣ **Comparator in Set / Map**

```cpp
struct cmp {
    bool operator()(int a, int b) {
        return a > b; // descending order
    }
};

set<int, cmp> s;
s.insert(1); s.insert(3); s.insert(2);

for(int x : s) cout << x << " "; // 3 2 1
```

* Custom comparator changes **ordering** in ordered containers
* Must **implement strict weak ordering** (`a==b → false`)

---

## 7️⃣ **Key Points / Rules**

1. **Return true if first element goes before second**
2. Can be **function pointer**, **lambda**, or **functor (struct/class)**
3. In `priority_queue`, the **comparator is reversed** (min-heap vs max-heap)
4. For `set/map`, comparator **must define strict weak ordering**

---

## 8️⃣ **Quick Reference Table**

| Use Case                  | Syntax / Example                                          |
| ------------------------- | --------------------------------------------------------- |
| `sort` ascending          | `sort(v.begin(), v.end());`                               |
| `sort` descending         | `sort(v.begin(), v.end(), [](int a,int b){return a>b;});` |
| Struct / object sorting   | `sort(v.begin(), v.end(), cmp);`                          |
| `priority_queue` min-heap | `priority_queue<int, vector<int>, greater<int>> pq;`      |
| `priority_queue` max-heap | `priority_queue<int> pq;`                                 |
| `set` custom order        | `set<int, cmp> s;`                                        |

---

### ✅ Tips for Interviews
1. For **objects**, define comparator on the **field you care about**
2. Use **lambda** for short inline comparators
3. Remember **priority_queue comparator logic is inverted**


```
bool comparator(Type a, Type b) {
    return a should go before b;
}
```