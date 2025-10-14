#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

// Use case: Graph with negative weights but no negative cycles.
// Time: O(V * E)
vector<int> bellmanFord(int n, vector<Edge> &edges, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto &e : edges) {
            if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v])
                dist[e.v] = dist[e.u] + e.w;
        }
    }

    // Detect negative cycle
    for (auto &e : edges) {
        if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
            cout << "Negative weight cycle detected\n";
            break;
        }
    }

    return dist;
}

int main() {
    int n = 5;
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };
    vector<int> dist = bellmanFord(n, edges, 0);
    for (int d : dist) cout << d << " ";
}
