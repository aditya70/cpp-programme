#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        for(int i=0;i<n/2;i++){
            char c=s[n-i-1];
            s[n-i-1]=s[i];
            s[i]=c;
        }
    }
};