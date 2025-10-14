// Option 1
void dfsUtil(int node, vector<vector<int>> &adj, vector<bool> &vis) {
    vis[node] = true;
    cout << node << " ";

    for (int nei : adj[node])
        if (!vis[nei])
            dfsUtil(nei, adj, vis);
}

void dfs(Graph &g, int start) {
    vector<bool> vis(g.n, false);
    dfsUtil(start, g.adj, vis);
}

// Option 2
void dfsIterative(Graph &g, int start) {
    vector<bool> vis(g.n, false);
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int node = st.top(); st.pop();
        if (vis[node]) continue;
        vis[node] = true;
        cout << node << " ";

        for (int nei : g.adj[node])
            if (!vis[nei])
                st.push(nei);
    }
}

// Option3 on Matrix (like grid problems)
void dfsGrid(vector<vector<int>> &grid, int r, int c) {
    int m = grid.size(), n = grid[0].size();
    if (r<0 || c<0 || r>=m || c>=n || grid[r][c]==0) return;
    grid[r][c] = 0; // mark visited

    dfsGrid(grid, r+1, c);
    dfsGrid(grid, r-1, c);
    dfsGrid(grid, r, c+1);
    dfsGrid(grid, r, c-1);
}
