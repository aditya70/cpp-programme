## 2️⃣ Algorithms in `<algorithm>` Header

STL **algorithms** are often more important than the containers themselves for interviews:

| Algorithm                               | Use Case                           |
| --------------------------------------- | ---------------------------------- |
| `sort` / `stable_sort`                  | Sort arrays, vectors               |
| `reverse`                               | Reverse sequence                   |
| `lower_bound` / `upper_bound`           | Binary search in sorted containers |
| `binary_search`                         | Check existence in sorted sequence |
| `max_element` / `min_element`           | Find max/min element               |
| `accumulate`                            | Sum elements (from `<numeric>`)    |
| `count`, `count_if`                     | Count occurrences                  |
| `next_permutation` / `prev_permutation` | Generate permutations              |
| `find`, `find_if`                       | Search in sequence                 |
| `unique`                                | Remove consecutive duplicates      |
| `merge`, `inplace_merge`                | Merge sorted sequences             |
| `partial_sort`, `nth_element`           | Kth largest/smallest               |

---

## 3️⃣ Other Utilities

| Utility            | Use Case                               |
| ------------------ | -------------------------------------- |
| `pair`             | Store 2 related values                 |
| `tuple`            | Store multiple related values          |
| `make_pair`, `tie` | Helper functions                       |
| `swap`             | Swap values efficiently                |
| `hash`             | Custom hashing in unordered containers |
| `std::function`    | Store function objects                 |

---

## 4️⃣ Common Interview Patterns Using STL

1. **Sliding window / Two pointers** → `deque`, `vector`, `set`
2. **Graph algorithms** → `vector<vector<int>>` for adjacency lists, `priority_queue` for Dijkstra
3. **Dynamic programming** → `vector`, `map` (for memoization)
4. **Frequency counting / top-K** → `map`, `unordered_map`, `multiset`, `priority_queue`
5. **Bit manipulation** → `bitset`
