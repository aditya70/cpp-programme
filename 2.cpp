#include <bits/stdc++.h>
using namespace std;

int maxGetNetVuln(vector<vector<int>> vulnerability){
    int n = vulnerability.size();
    int m = vulnerability[0].size();
    int ans = INT_MAX;
    
    // Choosing exactly m-1 rows
    for(int j=0;j<m;j++){
        vector<int> maxVuln(n-1,0);
        
        // Calculate max vulnerability for each column
        for(int i=0, k=0;i<n;i++){
            if(i==j) continue;
            maxVuln[k++] = vulnerability[i][j];
        }
        
        // Sort the vulnerabilities and take the m-1th element
        sort(maxVuln.begin(), maxVuln.end());
        ans = min(ans, maxVuln[m-2]);
    }
    
    return ans;
}


int main(){
    vector<vector<int> > v;
    vector<int> v1{ 1, 3, 1 };
    //vector<int> v1{1,3,1};
    vector<int> v2{3,1,1};
    vector<int> v3{1,2,2};
    vector<int> v4{1,1,3};
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    cout<<maxGetNetVuln(v)<<endl;
    return 0;
}