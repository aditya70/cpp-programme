#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        int l=s.length();
        for(int i=0;i<l;i++){
            if(iswalnum(s[i])) str+=tolower(s[i]);
        }
        return isPalimUtil(str);
    }
    bool isPalimUtil(string S){
        for (int i = 0; i < S.length() / 2; i++) {
             if (S[i] != S[S.length() - i - 1]) return false;
        }
        return true;
    }
};

int main(){
    Solution obj;
    cout<<obj.isPalindrome(" ");
    return 0;
}