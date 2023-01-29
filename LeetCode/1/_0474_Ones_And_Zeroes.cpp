#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[601][101][101];
    int count0(string s){
        int c=0;
        for(char& ch:s)if(ch=='0')c++;
        return c;
    }
    int solve(vector<string>& s, int m, int n, int idx){
        if(idx==s.size() || m+n==0)return 0;
        if(dp[idx][m][n]!=-1)return dp[idx][m][n];
        int zero=count0(s[idx]);
        int one=s[idx].size()-zero;
        int inc=0;
        if(zero<=m && one<=n)inc=1+solve(s,m-zero,n-one,idx+1);
        int excl=solve(s,m,n,idx+1);
        return dp[idx][m][n]=max(inc,excl);
    }
 
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(strs, m, n, 0);
    }
};