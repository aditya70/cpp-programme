#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int n; // number of vertices
    vector<vector<int>> adj; // adjacency list

    Graph(int n) {
        this->n = n;
        adj.resize(n);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // remove if directed
    }
};
