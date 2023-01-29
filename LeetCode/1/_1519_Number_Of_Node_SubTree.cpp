#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, unordered_set<int>> adj;
        for (auto& e : edges) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        vector<vector<int>> counts(n, vector<int>(26));
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            counts[i][labels[i] - 'a'] = 1;
            if (i != 0 && adj[i].size() == 1) q.push(i);
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            int p = *adj[curr].begin();
            adj[p].erase(curr);
            for (int i = 0; i < 26; ++i) counts[p][i] += counts[curr][i];
            if (p != 0 && adj[p].size() == 1) q.push(p);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)  ans[i] = counts[i][labels[i] - 'a'];
        return ans;
    }
};

int main(){
    return 0;
}