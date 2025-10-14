#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);

    for (int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;

    for(auto it=v.begin(); it!= v.end(); it++) cout<<*it<<" ";
    cout<<endl;

    vector<int>::iterator i;
    for ( i = v.begin(); i != v.end(); i++) cout<<*i<<" ";
    cout<<endl;

    for(int a:v) cout<<a<<" ";
    cout<<endl;
    return 0;
}