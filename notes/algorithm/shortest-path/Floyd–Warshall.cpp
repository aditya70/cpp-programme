#include <bits/stdc++.h>
using namespace std;

// Use case: Find shortest paths between all pairs of nodes.
// Time: O(V³), simple matrix DP.

void floydWarshall(vector<vector<int>> &dist) {
    int n = dist.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    const int INF = INT_MAX;
    vector<vector<int>> dist = {
        {0,   3,   INF, 5},
        {2,   0,   INF, 4},
        {INF, 1,   0,   INF},
        {INF, INF, 2,   0}
    };

    floydWarshall(dist);
    for (auto &row : dist) {
        for (int d : row)
            cout << (d == INF ? "INF" : to_string(d)) << " ";
        cout << "\n";
    }
}
