
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        
    // }
     bool isItPossible(string word1, string word2) {
        for(int i=0;i<word1.size();i++){
            for(int j=0;j<word2.size();j++){
                if(word1[i]!=word2[j]){
                    swap(word1,word2,i,j);
                    unordered_set<char> s1(word1.begin(),word1.end());
                    unordered_set<char> s2(word2.begin(),word2.end());
                    if(s1.size()==s2.size()) return true; 
                    else   swap(word1,word2,i,j);
                }
            }
        }
        return false;
    }

    void swap(string& w1, string& w2, int i, int j){
        char c=w1[i];
        w1[i]=w2[j];
        w2[j]=c;
    }
};