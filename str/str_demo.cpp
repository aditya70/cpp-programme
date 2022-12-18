#include <bits/stdc++.h>

using namespace std;

void print(string s){
    int n = s.length();
    for (int i = 0; i < n; i++){
        cout<<s[i];
    }
}

int main(){
    string str = "aditya";
    // print(str);
    char c_array[3];
c_array[0] = 'a';
c_array[1] = 'b';
c_array[2] = 'c';

for(int i=0 ; i<3 ; ++i)
{
  cout << c_array[i];
}
cout << endl;
    return 0;
}