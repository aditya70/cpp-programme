#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
         int n=board.size();
         vector<pair<int,int>> v(n*n+1);
         int num=1;
         vector<int> cols(n);
         iota(cols.begin(),cols.end(),0);
         for(int i=n-1;i>=0;i--){
             for(int col:cols){
                 v[num++]={i,col};
             }
             reverse(cols.begin(),cols.end());
         }
         vector<int> dp(n*n+1,-1);
         dp[1]=0;
         queue<int> q;
         q.push(1);
         while(!q.empty()){
             int curr=q.front();
             q.pop();
             for(int next=curr+1;next<=min(curr+6,n*n);next++){
                 pair<int,int> p=v[next];
                // cout<<p.first<<" "<<p.second<<endl;
                 int d=board[p.first][p.second] != -1 ? board[p.first][p.second] : next;
                 cout<<d<<endl;
                 if(dp[d]==-1){
                     dp[d]=dp[curr]+1;
                     q.push(d);
                 }
             }
         }
        // for(int b:dp)cout<<b<<" ";
         return dp[n*n];
    }
};