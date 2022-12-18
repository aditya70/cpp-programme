#include <bits/stdc++.h>

using namespace std;
int main(){
    set<int> s;
    s.insert(2);
    s.insert(3);
    set<int>::iterator it;
    for(it=s.begin();it!=s.end();it++) cout<<*it<<" ";
    cout<<endl;
    return 0;
}