#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int ans=-1;
        int a[n],b[n];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=0;i<trust.size();i++){
           a[trust[i][0]-1]++;  
           b[trust[i][1]-1]++;
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" "<<b[i]<<endl;
            if(a[i]==0 && b[i]==n-1){ans=i+1;break;}
        }
        return ans;
    }
};