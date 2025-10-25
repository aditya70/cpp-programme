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


/*
Option1: Structure
struct State {
    int x, y, mask;
};

queue<State> q;
q.push({x, y, z});

State cur = q.front();
q.pop();

int x = cur.x;
int y = cur.y;
int mask = cur.mask;

option2: 
// BFS queue: tuple (x, y, collectedKeysMask)
queue<tuple<int,int,int>> q;

q.emplace(x, y, z);

auto [x, y, mask] = q.front();
q.pop();

option3: Array
queue<array<int, 3>> q;

q.push({startX, startY, 0});

auto state = q.front();
q.pop();

int x = state[0];
int y = state[1];
int mask = state[2];

Option4: three separate queues
queue<int> qx, qy, qmask;

qx.push(startX);
qy.push(startY);
qmask.push(0);

int x = qx.front(); qx.pop();
int y = qy.front(); qy.pop();
int mask = qmask.front(); qmask.pop();

Option5:  use vector<int> instead of tuple
queue<vector<int>> q;  // each element: {x, y, mask}
q.push({startX, startY, 0});

auto state = q.front(); 
q.pop();

int x = state[0];
int y = state[1];
int mask = state[2];

*/