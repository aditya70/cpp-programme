#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_set<char> s1,s2;
        string st1="",st2="";
        for(char c:word1) {
            if(s1.find(c)==s1.end())
            s1.insert(c);
            else st1+=c;
        }
        for(char c:word2)
        {
            if(s2.find(c)==s2.end())
            s2.insert(c);
            else st2+=c;
        } 
        int n1=s1.size(), n2=s2.size();
        if(n1==n2) return true;
        else if(abs(n1-n2)>2) return false;
        else{
           if(n1<n2){
                if(st2.empty() || st1.empty()) return false;
           }  else {
                if(st1.empty() || st2.empty()) return false;
           }
        }
        return true;
    }
};

int main(){
    Solution s;
    cout<<s.isItPossible("a","bb")<<endl;
    return 0;
}