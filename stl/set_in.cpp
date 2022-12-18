#include <bits/stdc++.h>

using namespace std;
int n,a;
vector<int> v;

int main() {
    cin>>n;
    for(int i=0;i<n;i++) {cin>>a;v.push_back(a);}
    for(int i=0;i<v.size();i++) cout<<v[i]<< " ";
    return 0;
}