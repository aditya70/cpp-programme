#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dfs(int curr, vector<vector<int>>& adj, string& s, int& path) {
        int lc = 0, secondlc = 0;
        for (int child : adj[curr]) {
            int lcchild = dfs(child, adj, s, path);
            if (s[curr] == s[child]) continue;
            if (lcchild > lc) {
                secondlc = lc;
                lc = lcchild;
            } else if (lcchild > secondlc) {
                secondlc = lcchild;
            }
        }
        path = max(path, lc + secondlc + 1);
        return lc + 1;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) adj[parent[i]].push_back(i);
        int path = 1;
        dfs(0, adj, s, path);
        return path;
    }
};
   