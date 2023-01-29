#include <bits/stdc++.h>

using namespace std;

int main(){
    map<int,char> mp;
    mp[1]='a';
    mp.insert(pair<int,char> (2,'b'));
    mp[3]='c';
    mp.erase(2);
    map<int,char>::iterator itr;
     for (itr = mp.begin(); itr != mp.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    return 0;
}