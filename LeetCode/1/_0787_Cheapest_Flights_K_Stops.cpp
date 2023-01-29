#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int c=0;
        vector<vector<pair<int,int>>> adj(n);
       // for(int i=0;i<n;i++){adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});}
        for (auto& e : flights) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        queue<pair<int,int>> q;
        q.push({src,0});
        vector<int> v(n,INT_MAX);
        v[src]=0;
        while(c<=k && !q.empty()){
            int s=q.size();
            while(s--){
                auto [node,dist]=q.front();
                q.pop();
                for(auto& [nbr, price] : adj[node]){
                    if(dist+price>=v[nbr])continue;
                    v[nbr]=dist+price;
                    q.push({nbr,v[nbr]});
                }
            }
            c++;
        }
        return v[dst]==INT_MAX ? -1 : v[dst];
    }
};