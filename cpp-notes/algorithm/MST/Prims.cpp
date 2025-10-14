#include <bits/stdc++.h>
using namespace std;

// Use case: MST from adjacency list (like Dijkstra but for MST).
// Time: O(E log V)

int prims(int n, vector<vector<pair<int,int>>> &adj) {
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    key[0] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, 0});
    int totalWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        totalWeight += key[u];

        for (auto &[v, w] : adj[u]) {
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                pq.push({key[v], v});
            }
        }
    }
    return totalWeight;
}

int main() {
    int n = 5;
    vector<vector<pair<int,int>>> adj(n);
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({4, 7});
    adj[3].push_back({4, 9});

    cout << "MST Weight: " << prims(n, adj);
}
