#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int i,c[256] = {0};
        if (s.length() != t.length()) return false;
        for(i=0; s[i] && t[i]; i++) {
            c[s[i]]++; c[t[i]]--;
        }
        if (s[i] || t[i]) return false;
        for(i=0;i<256;i++) {
            if (c[i]!=0) return false;
        }
        return true;
    }
};

int main(){
    return 0;
}