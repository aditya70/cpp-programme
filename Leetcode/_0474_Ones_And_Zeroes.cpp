#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int count0(string s){
        int c=0;
        for(char& ch:s)if(ch=='0')c++;
        return c;
    }
    int solve(vector<string> s, int m, int n, int idx, vector<vector<vector<int>>>& v){
        if(idx==s.size() || m+n==0)return 0;
        if(v[m][n][idx]>0)return v[m][n][idx];
        int zero=count0(s[idx]);
        int one=s[idx].size()-zero;
        int inc=0;
        if(zero<=m && one<=n)inc=1+solve(s,m-zero,n-one,idx+1,v);
        int excl=solve(s,m,n,idx+1,v);
        v[m][n][idx]=max(inc,excl);
        return v[m][n][idx];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>> (n+1, vector<int> (strs.size()+1,0)));
        return solve(strs, m, n, 0, dp);
    }
};