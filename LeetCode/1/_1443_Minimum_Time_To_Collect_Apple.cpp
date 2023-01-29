#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int dfs(int child, int parent, vector<vector<int>>& adj, vector<bool>& hasApple){
        int totalTime=0,childTime=0;
        for(auto c: adj[child]){
            if(c==parent) continue;
            childTime = dfs(c,child,adj,hasApple);
            if(childTime || hasApple[c]) totalTime+=childTime+2;
        }
        return totalTime;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return dfs(0,-1,adj,hasApple);
    }
};