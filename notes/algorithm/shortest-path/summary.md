| Algorithm          | Handles              | Type          | Time         | Space   |
| ------------------ | -------------------- | ------------- | ------------ | ------- |
| **Dijkstra**       | No negative weights  | Single source | `O(E log V)` | `O(V)`  |
| **Bellman-Ford**   | Negative weights     | Single source | `O(VE)`      | `O(V)`  |
| **Floyd–Warshall** | Negative & all-pairs | All pairs     | `O(V³)`      | `O(V²)` |
| **Kruskal**        | Weighted edges       | MST           | `O(E log E)` | `O(V)`  |
| **Prim**           | Weighted edges       | MST           | `O(E log V)` | `O(V)`  |
