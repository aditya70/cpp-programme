#### https://leetcode.com/problems/shortest-path-visiting-all-nodes/
- BFS with bitmask	State = (node, visited mask)

```
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1) return 0; // only one node, zero edges needed
        int allMask = (1<<n)-1; // All 1 : 1111
        // queue stores pairs (node, visitedMask), BFS with bitmask
        // State = (node, visited mask).
        queue<pair<int,int>> q;
        // seen[node][mask] = true if we've already visited this state
        vector<vector<bool>> seen(n,vector<bool>(1<<n,false));
        
         // initialize: start from every node
         // Multi Source BFS
        for(int i=0;i<n;i++){
            q.push({i,1<<i});
            seen[i][1<<i];
        }

        int steps=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [u,mask]=q.front();
                q.pop();
                 // If mask indicates all nodes visited → return steps
                if(mask==allMask) return steps;
                // Explore neighbours
                for(int v:graph[u]){
                    int nextMask=mask|(1<<v);
                    if(!seen[v][nextMask]){
                        q.push({v,nextMask});
                        seen[v][nextMask]=true;
                    }
                }
            }
            steps++;
        }
        return -1; // theoretically should never happen since graph is connected
    }
};
```

```cpp
int nextMask = mask | (1 << v);
```

---

### 🧠 Step-by-step explanation:

#### 1. What is a “mask”?

A **mask** is just an integer used as a **bit representation of visited nodes**.
Each bit (0 or 1) corresponds to whether a node is visited.

For example, if we have `n = 4` nodes:

```
mask = 0b0110   // binary representation
```

means:

* Node 0 → bit 0 → 0 (not visited)
* Node 1 → bit 1 → 1 (visited)
* Node 2 → bit 2 → 1 (visited)
* Node 3 → bit 3 → 0 (not visited)

So, nodes {1, 2} have been visited.

---

#### 2. What does `(1 << v)` mean?

`1 << v` means "take 1 and shift it left by v bits."

That creates a number with **only the v-th bit set to 1**.

| `v` | Binary of `1 << v` | Meaning |
| --- | ------------------ | ------- |
| 0   | `0001`             | node 0  |
| 1   | `0010`             | node 1  |
| 2   | `0100`             | node 2  |
| 3   | `1000`             | node 3  |

So `(1 << v)` is a way to represent node `v` as a bitmask.

---

#### 3. What does `mask | (1 << v)` do?

The `|` operator is **bitwise OR**.
It combines the two bit patterns and sets a bit to 1 if it’s 1 in *either* operand.

So:

```cpp
mask | (1 << v)
```

means “mark node v as visited” in the current mask.

✅ Example:

```
mask     = 0b0110   // nodes 1,2 visited
(1 << v) = 0b0001   // we are now visiting node 0
---------------------------------
nextMask = 0b0111   // nodes 0,1,2 visited
```

So `nextMask` represents the new “visited” state after including node v.

---

#### 4. Why do we need it?

In the BFS algorithm:

* Each state = (current node, mask)
* When we move to a neighbor `v`, we must **update the visited set**.

That’s exactly what this line does — it tells BFS:
“Okay, if I go from `u` → `v`, I have now visited everything in `mask` plus node v.”

Then we push `(v, nextMask)` into the queue.

---

### 🔁 Quick summary:

| Concept    | Meaning                                 |                            |
| ---------- | --------------------------------------- | -------------------------- |
| `mask`     | bit representation of all visited nodes |                            |
| `(1 << v)` | bitmask representing node v             |                            |
| `mask      | (1 << v)`                               | union of visited nodes + v |
| `nextMask` | new visited-state after going to node v |                            |

-----
