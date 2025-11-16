#include <bits/stdc++.h>
using namespace std;

**Dijkstra’s Algorithm implementation in C++** using a priority queue (min-heap) for shortest path in a weighted graph (non-negative weights):
// Use case: Single-source shortest path in a weighted graph (no negative edges). 
// directed/undirected graph
// remove self loop and parallel edges
// Time: O(E log V) with priority queue.
vector<int> dijkstra(int n, vector<vector<pair<int,int>>> &adj, int src) {
    // Distance vector initialized to infinity
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Min-heap: (distance, node)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
       //  auto& [d, u] = pq.top(); pq.pop(); // wrong // reference to top element and then pop destroys that element. 
       // the reference d and u are dangling references — undefined behavior.
        auto [d, u] = pq.top(); pq.pop();

        // If we already found a better path
        if (d > dist[u]) continue; // skip outdated entries

        // Explore neighbors
        for (auto &[v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int n = 5;
    // vector<vector<int>>& graph; // graph[i] = (ui, vi, wi)
    // // ui is the source node, vi is the target node, and wi is weight
    vector<vector<pair<int,int>>> adj(n);
    // add edges: u, v, weight
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 2});

    vector<int> dist = dijkstra(n, adj, 0);
    cout << "Shortest distances from source 0:\n";
    for (int d : dist) cout << d << " ";
}

---

### 📘 **Explanation**

* `adj[u]` stores a list of pairs `{v, w}` meaning an edge from `u → v` with weight `w`.
* `priority_queue` keeps track of the next node with the smallest tentative distance.
* The algorithm repeatedly picks the unvisited node with the smallest distance and relaxes its edges.
* Time complexity: **O(E log V)**, where `E` is number of edges and `V` is number of vertices.
* Space complexity: **O(V + E)** for the adjacency list and distance array.

---

---

## 🧭 **🔹 DIJKSTRA’S ALGORITHM — OVERVIEW**

Dijkstra’s algorithm finds the **shortest path from a source node to all other nodes** in a weighted graph 
— provided **all edge weights are non-negative**.

---

## 💡 **🔹 Applications of Dijkstra’s Algorithm**

Here are its most common uses in **computer science, networking, and real life**:

---

### 🛰️ 1. **GPS & Map Navigation Systems**

* Used by **Google Maps, Apple Maps, etc.**
* Finds the **shortest route** between two locations.
* Nodes = intersections, edges = roads, weight = distance or travel time.

Example:

> Finding the fastest route from Seattle to San Francisco by minimizing driving time.

---

### 🌐 2. **Network Routing Protocols**

* Core algorithm behind **network routing protocols**:

  * **OSPF (Open Shortest Path First)**
  * **IS-IS (Intermediate System to Intermediate System)**
* Used to determine **optimal paths for data packets** across routers.

---

### 🏙️ 3. **Public Transportation Systems**

* Used to compute **shortest or fastest routes** in:

  * Bus, train, or subway networks.
* Helps find the least number of transfers or minimum travel time.

---

### ⚙️ 4. **Telecommunication & Internet Infrastructure**

* Used to **design efficient communication networks**:

  * Laying fiber optic cables.
  * Finding minimal-cost connection routes between nodes.

---

### 🕹️ 5. **Video Games (Pathfinding for AI)**

* Common in **game AI** for character movement.
* Example:

  * NPC finding the shortest path around obstacles on a map.

---

### 🧠 6. **Project Scheduling & Resource Optimization**

* Applied in **operations research**:

  * Minimizing task time in workflows.
  * Optimizing cost in logistics or manufacturing networks.

---

### 🧮 7. **Robotics and Motion Planning**

* Used in **autonomous robots** or drones to plan safe and short movement paths avoiding obstacles.

---

## ⚠️ **🔹 Limitations of Dijkstra’s Algorithm**

Despite its power, it has **several key limitations** 👇

---

### ❌ 1. **Cannot Handle Negative Edge Weights**

* Dijkstra assumes once a node’s shortest distance is found, it won’t change.
* Negative edges break that assumption.

  * Example: A → B (5), A → C (10), C → B (-10) → actual shortest is A→C→B=0, but Dijkstra won’t find it.
* Use **Bellman-Ford algorithm** instead.

---

### ⏳ 2. **Inefficient for Very Large Graphs**

* Time complexity = `O(E log V)` with a priority queue.
* For graphs with **millions of nodes**, it becomes computationally heavy.
* Use optimized versions like **A*** (for heuristics) or **Bidirectional Dijkstra**.

---

### 🌍 3. **Single-Source Limitation**

* It computes shortest paths from one source only.
* For **all-pairs shortest paths**, you need:

  * Run Dijkstra for each node → O(V * E log V)
  * Or use **Floyd-Warshall** or **Johnson’s algorithm**.

---

### 🚫 4. **Static Graph Assumption**

* Works only for **static graphs** — doesn’t handle dynamic changes in edge weights or topology (e.g., changing traffic conditions) efficiently.
* In dynamic cases, **incremental Dijkstra** or **real-time A*** variants are preferred.

---

### 💾 5. **Memory Usage**

* Requires storing adjacency lists, distances, and priority queues.
* For dense or weighted networks, this can consume significant memory.

---

## 🧩 **Summary Table**

| Category            | Description                                          |
| ------------------- | ---------------------------------------------------- |
| **Type**            | Greedy Algorithm                                     |
| **Time Complexity** | O(E log V) using min-heap                            |
| **Edge Constraint** | Works only with non-negative weights                 |
| **Applications**    | GPS, Network routing, Robotics, Games, Scheduling    |
| **Limitations**     | No negative weights, not dynamic, single-source only |

---


| Operation                  | How many times                                  | Cost per operation | Total        |
| -------------------------- | ----------------------------------------------- | ------------------ | ------------ |
| **Extract-min** from heap  | Once per node (`V` times)                       | `O(log V)`         | `O(V log V)` |
| **Relaxation / Insertion** | Once per edge (each edge may trigger an insert) | `O(log V)`         | `O(E log V)` |

So, total time =

O(V log V) + O(E log V)
≈ O((V + E) log V)
≈ O(E log V)   (since E ≥ V in most connected graphs)


```
LLONG_MAX = 9223372036854775807
But vector<int> dist stores only 32-bit signed int (~2e9)
So LLONG_MAX gets truncated → becomes a NEGATIVE number!
```