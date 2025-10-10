### Setup
```
#include <bits/stdc++.h> // includes all STL headers
using namespace std;
```
### ARRAYS
#### Declaration & Initialization
```
int arr[5] = {1, 2, 3, 4, 5};
int n = sizeof(arr) / sizeof(arr[0]);
```
#### Operations
```
sort(arr, arr + n);
reverse(arr, arr + n);
int mx = *max_element(arr, arr + n);
int mn = *min_element(arr, arr + n);
int sum = accumulate(arr, arr + n, 0);
bool found = binary_search(arr, arr + n, 3);
```
### VECTOR
#### Declaration & Initialization
```
vector<int> v = {1, 2, 3};     
v.push_back(4);                // {1, 2, 3, 4}
v.pop_back();                  // {1, 2, 3}
int x = v[1];                  // x = 2
```
#### Iteration
```
for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
for (int x : v) cout << x << " ";       // range-based loop
```
#### Operations
```
sort(v.begin(), v.end());                // sort ascending
reverse(v.begin(), v.end());             // reverse vector
v.erase(v.begin() + 1);                  // erase 2nd element
v.insert(v.begin(), 0);                  // insert 0 at start → {0,1,2,3}
v.clear();                               // remove all elements
bool empty = v.empty();                  // check if empty
```
### STRING
#### Declaration & Initialization
```
string s = "hello";
s += " world";              // "hello world"
char c = s[1];              // 'e'
```

#### Operations
```
s.size();                   // 11
s.substr(0, 5);             // "hello"  (start=0, length=5)
s.find("lo");               // 3  (first occurrence index)
s.erase(5);                 // remove from index 5 → "hello"
s.replace(0, 5, "hi");      // "hi"
reverse(s.begin(), s.end()); // reverse string
sort(s.begin(), s.end());   // sort characters
```
