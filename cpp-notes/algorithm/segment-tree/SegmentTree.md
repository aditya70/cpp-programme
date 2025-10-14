
## 🧩 1. What is a Segment Tree?

A **segment tree** is a **binary tree** where:

* Leaf nodes represent **array elements**.
* Internal nodes represent **merges of their children** (e.g., sum, min, max).
* Allows **range queries** in `O(log n)` and **point updates** in `O(log n)`.

---

### 🔹 Example Use Cases

| Operation               | Examples                                |
| ----------------------- | --------------------------------------- |
| Range Sum               | Sum of elements between indices L and R |
| Range Minimum / Maximum | Min/Max in subarray                     |
| Range GCD / LCM         | Greatest common divisor                 |
| Dynamic updates         | Update an element, recalc ranges        |

---

## 🧭 2. Implementation (C++)

### Classic **Recursive Segment Tree** for **Range Sum**

```cpp
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(vector<int> &arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, n - 1, 1);
    }

    void build(vector<int> &arr, int start, int end, int node) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(arr, start, mid, 2*node);
        build(arr, mid+1, end, 2*node+1);
        tree[node] = tree[2*node] + tree[2*node+1]; // merge
    }

    int query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;       // outside
        if (l <= start && end <= r) return tree[node]; // inside
        int mid = (start + end)/2;
        return query(2*node, start, mid, l, r) + 
               query(2*node+1, mid+1, end, l, r);
    }

    void update(int idx, int val) {
        update(1, 0, n-1, idx, val);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end)/2;
        if (idx <= mid) update(2*node, start, mid, idx, val);
        else update(2*node+1, mid+1, end, idx, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
};

int main() {
    vector<int> arr = {1,2,3,4,5};
    SegmentTree st(arr);

    cout << "Sum 1-3: " << st.query(1,3) << "\n"; // 2+3+4 = 9
    st.update(2, 10); // arr[2] = 10
    cout << "Sum 1-3 after update: " << st.query(1,3) << "\n"; // 2+10+4 = 16
}
```

---

## 🧩 3. Variations of Segment Tree

| Variation                   | Description                                    |
| --------------------------- | ---------------------------------------------- |
| **Range Min / Max / GCD**   | Change merge operation from sum to min/max/gcd |
| **Lazy Propagation**        | Efficient range updates (O(log n))             |
| **2D Segment Tree**         | For matrices (sum/min/max in submatrix)        |
| **Persistent Segment Tree** | Keep versions/history of updates               |
| **Dynamic Segment Tree**    | Handles very large arrays (10⁹ size)           |

---

## 🧠 4. Time Complexity

| Operation                | Complexity |
| ------------------------ | ---------- |
| Build                    | O(n)       |
| Point Update             | O(log n)   |
| Range Query              | O(log n)   |
| Range Update (with lazy) | O(log n)   |

---

## 🔹 5. Interview Problems Using Segment Tree

* Range Sum / Min / Max queries (static or dynamic)
* Count of numbers in a range
* Number of elements greater than X in a range
* Interval updates + queries (lazy propagation)
* Kth order statistics in subarray
* Maximum subarray sum (advanced)

# Segment Tree with Lazy Propagation
— this is essential for **range updates + range queries** efficiently in `O(log n)` per operation.

## 🧩 1. What is Lazy Propagation?

**Problem:** Standard segment tree updates a entire range `[L,R]` recursively.

* If the range is large → **O(n)** in worst case.

**Solution:**

* Use a **lazy array** to **defer updates**.
* Update nodes **only when necessary** (query or when visiting children).

This allows **range update + range query in O(log n)**.

---

## 🧭 2. Implementation (Range Sum + Range Update)

```cpp
#include <bits/stdc++.h>
using namespace std;

class LazySegmentTree {
    vector<int> tree, lazy;
    int n;

public:
    LazySegmentTree(vector<int> &arr) {
        n = arr.size();
        tree.resize(4*n);
        lazy.resize(4*n, 0);
        build(arr, 0, n-1, 1);
    }

    void build(vector<int> &arr, int start, int end, int node) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start+end)/2;
        build(arr, start, mid, 2*node);
        build(arr, mid+1, end, 2*node+1);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    void updateRange(int l, int r, int val) {
        updateRange(1, 0, n-1, l, r, val);
    }

    void updateRange(int node, int start, int end, int l, int r, int val) {
        // apply pending lazy updates
        if (lazy[node] != 0) {
            tree[node] += (end-start+1)*lazy[node];
            if (start != end) {
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }

        // no overlap
        if (r < start || end < l) return;

        // complete overlap
        if (l <= start && end <= r) {
            tree[node] += (end-start+1)*val;
            if (start != end) {
                lazy[2*node] += val;
                lazy[2*node+1] += val;
            }
            return;
        }

        // partial overlap
        int mid = (start+end)/2;
        updateRange(2*node, start, mid, l, r, val);
        updateRange(2*node+1, mid+1, end, l, r, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    int queryRange(int l, int r) {
        return queryRange(1, 0, n-1, l, r);
    }

    int queryRange(int node, int start, int end, int l, int r) {
        // apply pending lazy updates
        if (lazy[node] != 0) {
            tree[node] += (end-start+1)*lazy[node];
            if (start != end) {
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }

        // no overlap
        if (r < start || end < l) return 0;

        // complete overlap
        if (l <= start && end <= r) return tree[node];

        // partial overlap
        int mid = (start+end)/2;
        return queryRange(2*node, start, mid, l, r) +
               queryRange(2*node+1, mid+1, end, l, r);
    }
};

int main() {
    vector<int> arr = {1,2,3,4,5};
    LazySegmentTree st(arr);

    cout << "Sum 1-3: " << st.queryRange(1,3) << "\n"; // 2+3+4 = 9
    st.updateRange(1,3,10); // add 10 to index 1,2,3
    cout << "Sum 1-3 after update: " << st.queryRange(1,3) << "\n"; // 12+13+14 = 39
    cout << "Sum 0-4: " << st.queryRange(0,4) << "\n"; // total sum
}
```

---

## 🧠 3. How Lazy Propagation Works

1. **Lazy array** stores **pending updates**.
2. On visiting a node:

   * Apply the pending update to the current node.
   * Push the update to children (if internal node).
3. Only recursively update children **when necessary** (query or deeper update).

✅ This reduces **range update complexity** from `O(n)` → `O(log n)`.

---

## 🔹 4. Variations of Lazy Segment Tree

| Variation                | Use case                                       |
| ------------------------ | ---------------------------------------------- |
| Range min / max queries  | Segment tree merge = min/max                   |
| Range assignment         | Assign values instead of addition              |
| 2D segment tree          | Matrix sum / min / max                         |
| Persistent segment tree  | Keep history of versions                       |
| XOR / GCD / custom merge | Can replace sum with any associative operation |



# Segment Tree with Lazy Propagation for Range Minimum / Maximum

extremely powerful for **range updates + queries**, and frequently asked in **hard Google/LeetCode problems**.

Queries — this is a very common interview pattern, especially for problems like “range update + query” or “interval problems.”

Perfect! ⚡ Let’s implement **Segment Tree with Lazy Propagation for Range Minimum / Maximum Queries** — this is a **very common interview pattern**, especially for problems like “range update + query” or “interval problems.”


## 🧩 1. Key Idea

* Each node stores **min or max** of its segment.
* Lazy array stores **pending updates**.
* Update/query **propagates only when necessary**.

---

## 🧭 2. Implementation (C++17)

### Segment Tree with Lazy Propagation (Range Min + Range Add Update)

```cpp
#include <bits/stdc++.h>
using namespace std;

class LazySegmentTreeMin {
    vector<int> tree, lazy;
    int n;
    const int INF = INT_MAX;

public:
    LazySegmentTreeMin(vector<int> &arr) {
        n = arr.size();
        tree.resize(4*n, INF);
        lazy.resize(4*n, 0);
        build(arr, 0, n-1, 1);
    }

    void build(vector<int> &arr, int start, int end, int node) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end)/2;
        build(arr, start, mid, 2*node);
        build(arr, mid+1, end, 2*node+1);
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }

    void updateRange(int l, int r, int val) {
        updateRange(1, 0, n-1, l, r, val);
    }

    void updateRange(int node, int start, int end, int l, int r, int val) {
        // Apply pending lazy updates
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (start != end) {
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }

        // No overlap
        if (r < start || end < l) return;

        // Complete overlap
        if (l <= start && end <= r) {
            tree[node] += val;
            if (start != end) {
                lazy[2*node] += val;
                lazy[2*node+1] += val;
            }
            return;
        }

        // Partial overlap
        int mid = (start + end)/2;
        updateRange(2*node, start, mid, l, r, val);
        updateRange(2*node+1, mid+1, end, l, r, val);
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }

    int queryMin(int l, int r) {
        return queryMin(1, 0, n-1, l, r);
    }

    int queryMin(int node, int start, int end, int l, int r) {
        // Apply pending lazy updates
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (start != end) {
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }

        // No overlap
        if (r < start || end < l) return INF;

        // Complete overlap
        if (l <= start && end <= r) return tree[node];

        // Partial overlap
        int mid = (start + end)/2;
        return min(
            queryMin(2*node, start, mid, l, r),
            queryMin(2*node+1, mid+1, end, l, r)
        );
    }
};

int main() {
    vector<int> arr = {5, 2, 6, 3, 1, 7};
    LazySegmentTreeMin st(arr);

    cout << "Min 1-4: " << st.queryMin(1,4) << "\n"; // min(2,6,3,1)=1
    st.updateRange(2,4,5); // add 5 to indices 2,3,4
    cout << "Min 1-4 after update: " << st.queryMin(1,4) << "\n"; // min(2,11,8,6)=2
    cout << "Min 0-5: " << st.queryMin(0,5) << "\n"; // overall min
}
```

---

## 🧠 3. Notes

* To **switch to max queries**, change `min` → `max` in build, update, query.
* Lazy propagation works with **any associative operation** like sum, min, max, xor.
* Time complexity:

  * Build: `O(n)`
  * Query: `O(log n)`
  * Range update: `O(log n)`

---

## 🔹 4. Common Interview Problems

* Range min/max queries with updates
* Number of elements in a range
* Interval scheduling problems
* Maximum subarray sum with updates
* RMQ (Range Minimum Query) on large datasets

# Segment Tree with Lazy Propagation, supporting both range addition and range assignment.

This is common in Google-level hard problems, e.g., interval updates with queries.
