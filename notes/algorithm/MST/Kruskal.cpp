#include <bits/stdc++.h>
using namespace std;

// Use case: Minimum spanning tree using edge list sorting + DSU.
// Time: O(E log E)

struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return true;
    }
};

struct Edge {
    int u, v, w;
};

int kruskal(int n, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), [](auto &a, auto &b) { return a.w < b.w; });
    DSU dsu(n);
    int mstWeight = 0;

    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v))
            mstWeight += e.w;
    }
    return mstWeight;
}

int main() {
    int n = 4;
    vector<Edge> edges = {
        {0,1,10}, {0,2,6}, {0,3,5}, {1,3,15}, {2,3,4}
    };
    cout << "MST weight: " << kruskal(n, edges);
}
