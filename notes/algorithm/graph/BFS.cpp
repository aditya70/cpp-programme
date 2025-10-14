// Option 1
void bfs(Graph &g, int start) {
    vector<bool> vis(g.n, false);
    queue<int> q;
    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";

        for (int nei : g.adj[node]) {
            if (!vis[nei]) {
                vis[nei] = true;
                q.push(nei);
            }
        }
    }
}

// Option2 for BFS on Matrix (like grid problems)
int bfsGrid(vector<vector<int>> &grid, pair<int,int> start) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int,int>> q;
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    q.push(start);
    vis[start.first][start.second] = true;
    int steps = 0;

    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto [r,c] = q.front(); q.pop();
            for (auto [dr,dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==1) {
                    vis[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
        steps++;
    }
    return steps;
}
