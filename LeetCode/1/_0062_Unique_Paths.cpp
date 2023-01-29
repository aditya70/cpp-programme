#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
         int dp[n];
         memset(dp, 0, sizeof(dp));
         dp[0]=1;
         for(int i=0; i<m;i++){
            for(int j=1;j<n;j++) dp[j]+=dp[j-1];
         }
         return dp[n-1];
    }
};

int main() {
    Solution s;
    s.uniquePaths(2, 4);
    return 0;
}