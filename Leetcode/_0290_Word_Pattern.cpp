#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
 bool wordPattern(string pattern, string s) {
        vector<string> v;
        splitPat(s, v," ");
        if(pattern.size()!=v.size()) return false;
        map<char,string> m;
        map<string,char> m2;
        for(int i=0;i<pattern.size();i++){
            if(m.find(pattern[i])!=m.end()){
                if(m[pattern[i]]!=v[i]) {
                    return false;
                }
            }
            if(m2.find(v[i])!=m2.end() && m2[v[i]]!=pattern[i]) return false;
            m[pattern[i]]=v[i];
            m2[v[i]]=pattern[i];
        }
        return true;
    }
    void splitPat(string pattern, vector<string>& v, string delimeter){
        int start=0;
        int end=pattern.find(delimeter);
        while(end != -1){
            v.push_back(pattern.substr(start, end-start));
            start=end+delimeter.size();
            end=pattern.find(delimeter, start);
        }
        v.push_back(pattern.substr(start,end));
    }
};

int main(){
    Solution s;
    cout<<"ans "<<s.wordPattern("abba","dog dog dog dog");
    return 0;
}