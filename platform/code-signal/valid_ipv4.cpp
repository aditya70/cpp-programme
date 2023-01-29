#include <bits/stdc++.h>
using namespace std;
// for string delimiter
vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;
    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}
bool valid(string s){
    int n=0,a,c=0;
    for(int i=0;i<s.length();i++){
        if(s[i]<48 || s[i]>57)return false;
        a=s[i]-'0';
        n=n*10+a;
        c++;
    }
    cout<<"c "<<c<<" "<<s.length()<<endl;
    if(n<0||n>255)return false;
    // if(c!=s.length() || (c>1&&n==0))return false;
    int num_len=0;
    if(n==0)num_len=1;
    while(n){num_len++;n=n/10;}
    if(num_len!=s.length())return false;
    return true;
}
bool solution(string inputString) {
    vector<string> v=split(inputString,".");
    if(v.size()!=4)return false;
    for(auto& s:v)if(s.length()==0 || s.length()>3 ||!valid(s))return false;
    return true;
}
int main(){
    cout<<solution("11.224.32.14")<<endl;
    return 0;
}