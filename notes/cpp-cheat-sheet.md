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

#### SET
#### Declaration & Initialization
```
set<int> s = {1, 3, 5};
s.insert(2);                 // {1, 2, 3, 5}
s.erase(3);                  // {1, 2, 5}
bool has = s.count(2);       // true
```

#### Iteration
```
for (int x : s) cout << x << " "; // prints sorted unique elements
```

#### Notes
- Automatically sorted (ascending by default)
- Stores unique elements

### VECTOR
```
vector<int> v = {1, 2, 3};
v.push_back(4);         // {1, 2, 3, 4}
v.pop_back();           // {1, 2, 3}
v.size();               // 3
v.clear();              // {}
v.empty();              // true if empty
v.front();              // first element
v.back();               // last element

// iteration
for (int x : v) cout << x << " ";        // range loop
for (int i = 0; i < v.size(); i++) cout << v[i] << " "; // index loop

sort(v.begin(), v.end());                // ascending
reverse(v.begin(), v.end());             // reverse
auto it = find(v.begin(), v.end(), 3);   // iterator to 3
v.erase(v.begin() + 1);                  // removes 2nd element
v.insert(v.begin(), 10);                 // {10, 1, 2, 3}
```

### PAIR
```
pair<int, string> p = {1, "abc"};
cout << p.first << " " << p.second; // 1 abc

pair<int, pair<int, int>> p2 = {1, {2, 3}};
cout << p2.second.first; // 2
```

### SET (Sorted, Unique Elements)
```
set<int> s = {3, 1, 4};
s.insert(2);          // {1, 2, 3, 4}
s.erase(3);           // {1, 2, 4}
cout << s.count(2);   // 1 (true)
auto it = s.find(2);  // iterator to 2
if (it != s.end()) s.erase(it); // removes 2

s.empty();            // false if not empty
s.size();             // number of elements
```

### MULTISET (Sorted, Allows Duplicates)
```
multiset<int> ms = {1, 1, 2};
ms.insert(2);             // {1, 1, 2, 2}
ms.erase(ms.find(1));     // removes only one occurrence → {1, 2, 2}
ms.count(2);              // 2 occurrences
```

### UNORDERED_SET (Faster, Unsorted, Unique)
```
unordered_set<int> us = {5, 2, 7};
us.insert(3);             // {5, 2, 7, 3} (order not guaranteed)
us.erase(2);              // removes 2
bool exists = us.count(7); // true
us.find(5) != us.end();    // true if found

// average O(1) time, unordered (uses hash table)
```

### MAP (Sorted Key-Value)
```
map<char, int> m;
m['a'] = 2;
m['b'] = 3;

for (auto &p : m)
    cout << p.first << " " << p.second << "\n"; 
// Output:
// a 2
// b 3

m.count('a');   // 1 if exists
m.erase('b');   // remove key 'b'
```

### UNORDERED_MAP (Faster, Unsorted Key-Value)
```
unordered_map<char, int> um;
um['x']++;
um['y'] += 5;

for (auto &p : um)
    cout << p.first << ":" << p.second << " "; // order not guaranteed
```

### STACK (LIFO)
```
stack<int> st;
st.push(10);     // [10]
st.push(20);     // [10,20]
st.top();        // 20
st.pop();        // removes 20 → [10]
st.empty();      // false
```

### QUEUE (FIFO)
```
queue<int> q;
q.push(1);      // [1]
q.push(2);      // [1,2]
q.front();      // 1
q.back();       // 2
q.pop();        // removes 1 → [2]
```

### PRIORITY QUEUE (Heap)
```
priority_queue<int> pq;         // max-heap by default
pq.push(3); pq.push(5); pq.push(1); // [5,3,1]
pq.top();                       // 5
pq.pop();                       // removes 5

priority_queue<int, vector<int>, greater<int>> minpq; // min-heap
minpq.push(3); minpq.push(1);
minpq.top();                   // 1
```

### DEQUE (Double Ended Queue)
```
deque<int> dq;
dq.push_front(1);  // [1]
dq.push_back(2);   // [1,2]
dq.pop_front();    // [2]
dq.pop_back();     // []
```
### ALGORITHMS
```
sort(v.begin(), v.end());            // sort ascending
reverse(v.begin(), v.end());         // reverse order
max_element(v.begin(), v.end());     // pointer to max element
min_element(v.begin(), v.end());     // pointer to min element
accumulate(v.begin(), v.end(), 0);   // sum of elements
count(v.begin(), v.end(), 2);        // count of 2s
find(v.begin(), v.end(), 3);         // iterator to 3 or v.end()
unique(v.begin(), v.end());          // remove adjacent duplicates
next_permutation(v.begin(), v.end()); // next lexicographic order
```

### SHORTCUT MACROS (for speed)
```
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second

sort(all(v));   // shorter syntax
v.pb(10);       // v.push_back(10)

#### FAST I/O
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

### TEMPLATE FOR CONTESTS
```
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
#define int long long
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &x : v) cin >> x;
        sort(all(v));
        cout << v.back() << "\n";
    }
}
```
