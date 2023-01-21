#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool valid(string& s, int i, int l){
        if(l==1) return 1;
        else{
            string tmp=s.substr(i,l);
            if(s[i]!='0' && (l<3||tmp<="255")) return 1;
        }
        return 0;
    }

    void f(string& s, int i, vector<int>& v, vector<string>& a){
        int l=s.length()-i, n=v.size(),x=4-n;
        if(l<x || l>3*x) return;
        if(n==3){
            if(valid(s,i,l)){
                int e = 0;
                string str;
                for (int j=0;j<n;j++) {
                    str.append(s.substr(e, v[j]));
                    e += v[j];
                    str.append(".");
                }
                str.append(s.substr(i));
                a.push_back(str);
            }
            return;
        }
        for (int k = 1; k <= 3 && k <= l; k++) {
            v.push_back(k);
            if (valid(s, i, k)) f(s, i + k, v, a);
            v.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> a;
        vector<int> v;
        f(s,0,v,a);
        return a;
    }
};