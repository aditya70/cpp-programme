#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    void bfs(int s, vector<int>& edges, vector<int>& d){
        int n=edges.size();
        d[s]=0;
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(!vis[node]){
                vis[node]=true;
                int nbr=edges[node];
                if(nbr!=-1 && !vis[nbr]){
                    d[nbr]=d[node]+1;
                    q.push(nbr);
                }
            }
        }
        
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
       int n=edges.size(), mind=-1,currmind=INT_MAX;
       vector<int> d1(n,INT_MAX), d2(n, INT_MAX);
       bfs(node1, edges, d1);
       bfs(node2, edges, d2);
       for(int i=0;i<n;i++){
           if(currmind>max(d1[i],d2[i])){
               mind=i;
               currmind=max(d1[i],d2[i]);
           }
       }
       return mind;
    }
};