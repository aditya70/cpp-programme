#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void f(string& s, int start, vector<string>& t ,vector<vector<bool>>& v,vector<vector<string>>& ans){
        if(start>=s.size()) ans.push_back(t);
        for(int i=start;i<s.size();i++){
            if(s[start]==s[i] && (i-start<=2 || v[start+1][i-1])){
                v[start][i]=true;
                t.push_back(s.substr(start,i-start+1));
                f(s,i+1,t,v,ans);
                t.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> t;
        int n=s.size();
        vector<vector<bool>> v(n, vector<bool>(n, false));
        f(s,0,t,v,ans);
        return ans;
    }
};