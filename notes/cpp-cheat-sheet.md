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
