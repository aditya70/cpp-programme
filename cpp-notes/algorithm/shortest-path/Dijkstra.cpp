#include <bits/stdc++.h>
using namespace std;

// Use case: Single-source shortest path in a weighted graph (no negative edges).
// Time: O(E log V) with priority queue.
vector<int> dijkstra(int n, vector<vector<pair<int,int>>> &adj, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue; // skip outdated entries

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
    vector<vector<pair<int,int>>> adj(n);
    // add edges: u, v, weight
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 2});

    vector<int> dist = dijkstra(n, adj, 0);
    for (int d : dist) cout << d << " ";
}
