#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1=s.length(), n2=t.length();
        if(n1!=n2) return false;
        int sc[26]={0}, tc={0};
        for(int i=0;i<n1;i++){
            sc[s[i]-'a']++;
            tc[t[i]-'a']++;
        }
        for(int i=0;i<n1;i++){
            if(sc[s[i]-'a'] != tc[t[i]-'a']) return false;
        }
        return true;
    }
};