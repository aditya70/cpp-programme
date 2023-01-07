#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
      bool detectCapitalUse(string word) {
        int n=word.size();
        if(n==1) return true;
        char c1=word[0],c2=word[1];
        if((65<=c1 && c1<=90) && (65<=c2 && c2<=90)) return upper(word);
        else if((97<=c1 && c1<=122) && (97<=c2 && c2<=122)) return lower(word);
        else if((65<=c1 && c1<=90) && (97<=c2 && c2<=122)) return lower(word.substr(1));
        else return false;
    }
    bool upper(string word){
        for(char c:word){
            if(c<65 || c>90) return false;
        }
        return true;
    }
    bool lower(string word){
        for(char c:word){
            if(c<97 || c>122) return false;
        }
        return true;
    }
};

