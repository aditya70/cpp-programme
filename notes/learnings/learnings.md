
priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq(k); // priority_queue does not have a constructor that takes an integer k.
Default constructor: priority_queue<T, Container, Compare> pq;
From a container: priority_queue<T, Container, Compare> pq(Container &c, Compare comp);

priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
Then push all elements. If you want to limit the heap to size k, do it manually:
for (auto& [x,y] : f) {
    pq.push({x,y});
    if (pq.size() > k) pq.pop();
}

```
struct cmp {
    bool operator()(pair<int,int> a, pair<int,int> b){
        // min heap for heap - it's opposite to vector,set where it is descending order
        return a.second>b.second;
    }
};
```

- priority_queue<ListNode*, vector<ListNode*>, cmp> pq;


 * Your Trie object will be instantiated and called as such:
 // new Trie() = dynamically allocates a new Trie object on the heap
 * Trie* obj = new Trie(); // Pointer for new keyword // Trie* obj = pointer to a Trie object
 * Valid:  Trie obj;obj.insert("apple");

child(26, nullptr); // is not valid inside the constructor body // it looks like a function call, not a constructor call.
```
Option 1 (Initializer List – preferred)
class Trie {
    vector<Trie*> child;
    bool isEnd;
public:
    Trie() : child(26, nullptr), isEnd(false) {}
};
This works because child(26, nullptr) calls the vector’s constructor before the object is created.
```

- nullptr is better than NULL
```
class MapSum {
    struct TrieNode {
        vector<TrieNode*> children;
        int sum;   // cumulative sum for all keys through this prefix
        TrieNode() : children(26, nullptr), sum(0) {}
    };

    TrieNode* root;
    unordered_map<string, int> keyToVal;

public:
    MapSum() {
        root = new TrieNode();
    }
```

```
struct TrieNode {
    vector<TrieNode*> child;
    int sum;
    TrieNode() : child(26, nullptr), sum(0) {}
};

class MapSum {
    // Option1
    TrieNode* root;
    // Option2
    //TrieNode* root = new TrieNode(); 
    unordered_map<string, int> keyToVal;
    public:
    MapSum() {
        root = new TrieNode();
    }
}
```

```
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string word;
    TrieNode() : word("") {}
};
```

```
// Bitwise Trie
struct TrieNode {
    TrieNode* child[2]; // 0 or 1
    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

```

```
class WordFilter {
    struct TrieNode {
        TrieNode* children[27]; // 26 letters + '#'
        int weight;
        TrieNode() : weight(-1) {
            fill(begin(children), end(children), nullptr);
        }
    };

    TrieNode* root;

```

#### split string by space
```
string sentence;
stringstream ss(sentence);
string word; // stores splitted string by space
while (ss >> word) {

}

vector<pair<int,int>> dirs={{-1,0},{1,0},{0,-1},{0,1}}; // for (auto& [x,y]:dirs)
~~vector<vector<int>>> dirs={{-1,0},{1,0},{0,-1},{0,1}};~~ // for (auto& [x,y]:dirs) // cannot decompose vector


vector<string> v;
unordered_set<string> s(v.begin(), v.end());  // unordered_set constructor (faster initialization)

char ch='2' // ch+1= '3' , ch-1='2'
char ch = 'b' // ch+1='c', ch-1='a'

vector<string> board=vector<string>(n,string(n,'.')); // string of size n with .

set<string> result;
vector<string> v(result.begin(), result.end()); //. vector from set
return vector<string>(result.begin(), result.end());

```
vector<string> v;
// set<string> result; // result is set container, it can be other container
v.insert(v.end(), result.begin(), result.end()); //  insert at the end of vector
```

#### iota
- iota is a C++ STL algorithm that fills a range with sequentially increasing values.
#include <numeric>  // Required header

iota(start_iterator, end_iterator, starting_value);
What it does:
Fills the range [start, end) with: starting_value, starting_value+1, starting_value+2, ...
vector<int> parent(26);
iota(parent.begin(), parent.end(), 0);

// Result: parent = [0, 1, 2, 3, 4, ..., 25]

// Example 1: Fill with 0, 1, 2, 3, 4
vector<int> v(5);
iota(v.begin(), v.end(), 0);
// v = [0, 1, 2, 3, 4]

// Example 2: Start from 10
vector<int> v(5);
iota(v.begin(), v.end(), 10);
// v = [10, 11, 12, 13, 14]

// Example 4: Works with other types
vector<char> chars(5);
iota(chars.begin(), chars.end(), 'a');
// chars = ['a', 'b', 'c', 'd', 'e']

// Example 5: Array
int arr[5];
iota(arr, arr + 5, 100);
// arr = [100, 101, 102, 103, 104]


string stream, word;
int maxLen;
maxLen=max(maxLen,(int)word.size()); // typecast is necessary because of a type mismatch between int and size_t.
**Why it fails:**
- `maxLen` is `int` (signed)
- `word.size()` returns `size_t` (unsigned, typically `unsigned long` or `unsigned long long`)
- `max()` requires **both arguments to be the same type**


###### erase
// By position
s.erase(pos);           // Erase from pos to end
s.erase(pos, len);      // Erase len chars starting at pos

// By iterator
s.erase(it);            // Erase single char at iterator
s.erase(start, end);    // Erase range [start, end)
// Clear
s.erase();              // Clear entire string
s.clear();              // Same as erase()

Examples
string s = "Hello";
s.erase();  // Empty string
// or
s.clear();  // Same result

string s = "Hello Beautiful World";

// Find and erase "Beautiful "
size_t pos = s.find("Beautiful");
if (pos != string::npos) { 
    s.erase(pos, 10);  // "Beautiful " is 10 chars
}

1. Erase by Position and Length
string s = "Hello World";
// Erase 6 characters starting from index 5
s.erase(5, 6); // Output: "Hello"
// Erase from index 3 to end (length not specified)
s.erase(3); // Output: "Hel"

2. Erase Range with Iterators
string s = "Hello World";
// Erase from index 5 to 10 (not including 10)
s.erase(s.begin() + 5, s.begin() + 10); // Output: "Hellod"

// Erase first 5 characters
s.erase(s.begin(), s.begin() + 5); // Output: "d"

// Erase last 3 characters
s.erase(s.end() - 3, s.end());


int num; 
// check all 32 bits of num from MSB(31)- Most Significant bit to LSB(0) - Least Significant bit
for(int i=31;i>=0;i--){
    int bit = (num >> i) & 1; // num/ 2^i  // checks ith bit is set or not
}

1 << i = 1 * 2^i // multiplication


```
vector<vector<string>>& result
vector<string>& path
vector<string> onePath(path.rbegin(), path.rend());
result.push_back(onePath); // right
result.push_back(path.begin(),path.end()); // wrong
vector<string>& wordList
unordered_set<string> wordSet(wordList.begin(),wordList.end()); // vector to set
unordered_set<string> visitedThisLevel;
for (auto &w : visitedThisLevel) {
    wordSet.erase(w);
}
```

queue<pair<int,int>> q;

// push: constructs pair first, then copies/moves it
q.push({x, y});           // Creates temporary pair, then pushes
q.push(make_pair(x, y));  // Explicit pair creation

// emplace: constructs pair directly in-place
q.emplace(x, y);          // Constructs pair directly in queue (no temp)

// push needs a complete object or braces
q.push({x, y});           // ✅ Works
q.push(x, y);             // ❌ Error! Needs a pair

// emplace takes constructor arguments directly
q.emplace(x, y);          // ✅ Works - forwards to pair constructor
q.emplace({x, y});        // ✅ Also works, but defeats the purpose

```

```
int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}}; // 4 neighbours of cell

for(auto& d:dir){
    int nx=x+d[0];
    int ny=y+d[1];
}

```
string &s;
int zeros = count(s.begin(), s.end(), '0');
int ones = s.size() - zeros;
```

```
This is the top-down recursive equivalent of 2D knapsack.
Each dimension (m, n) represents a capacity (resource).
idx adds a third dimension → which items we can still consider.
Classic pattern: “include/exclude + memoization”.

1 <= strs.length <= 600
1 <= strs[i].length <= 100

// dp[idx][m][n] = the maximum number of strings we can form
starting from index idx (the current string),
when we still have m zeros and n ones available.

int dp[601][101][101];
memset(dp,-1,sizeof(dp));

```

```
vector<int>& nums 
int total = accumulate(nums.begin(), nums.end(), 0); // total sum
```

```
unordered_map<int, int> memo;

// As you insert elements:
memo[1] = 10;  // Capacity too small, rehash!
memo[2] = 20;  // Capacity too small, rehash!
memo[3] = 30;  // Capacity too small, rehash!
// ... multiple expensive rehashing operations

unordered_map<int, int> memo;
memo.reserve(1000);  // Pre-allocate for 1000 elements

memo[1] = 10;  // ✅ No rehash
memo[2] = 20;  // ✅ No rehash
memo[3] = 30;  // ✅ No rehash
// ... all insertions are faster

// Similar concept for vector
vector<int> v;
v.reserve(1000);  // Pre-allocate space for 1000 elements

// vs unordered_map
unordered_map<int, int> m;
m.reserve(1000);  // Pre-allocate buckets for ~1000 elements

// Dynamic programming with known state space
int n = 20;
unordered_map<int, int> dp;
dp.reserve(1 << n);  // Will have at most 2^20 states

// Processing large input
vector<int> nums(100000);
unordered_map<int, int> freq;
freq.reserve(nums.size());
for (int x : nums) freq[x]++;

```

map<int,int> mp; // start → end

auto it = mp.lower_bound(start);
auto prev = std::prev(it);

```

vector<pair<int,int>> intervals;
intervals.emplace_back(startTime, endTime); // int startTime, endTime

```

ch= 'a'
string str=string(ch, 5); // aaaaa

```

```
vector<vector<int>>& intervals;

// ascendign sorting
sort(intervals.begin(), intervals.end(),
    [](const vector<int>& a, const vector<int>& b){
        return a[0] < b[0];
    });

// ascending sorting
sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
});


struct Interval {
    int start, end;
};

// sort by end time ascending
bool cmp(Interval a, Interval b) {
    if(a.start==b.start){
        return a.end<b.end;
    }
    return a.start<b.start;
}
vector<Interval> v;
sort(v.begin(),v.end(),cmp); // ascending sorting

```
srand(time(0));       // Seed once
int x = rand();       // Returns random int (0 to RAND_MAX)
int x = rand() % 100; // 0 to 99 (but biased!)
int random=rand() // random numbers
int idx = rand()%10 // 0 to 9 index

```

double r = ((double) rand() / RAND_MAX) * total;

rand() returns an integer from 0 to RAND_MAX

To convert it into a real number from 0 to 1, we divide by RAND_MAX

Then we scale it up by total

This gives a value in: [0, total)

```

```
unordered_map<int, int> indegree;
unordered_map<int, unordered_set<int>> graph;

```

```
struct State {
    string board;
    unordered_map<char,int> hand;
    int moves;

    State(string b, unordered_map<char,int> h, int m)
        : board(b), hand(h), moves(m) {}
};


State init(board, handCount, 0);


// This is called aggregate initialization (also known as brace initialization or uniform initialization in C++11+).
struct State {
    string board;
    unordered_map<char,int> hand;
    int moves;
};


State init { "RRBBY", {{'R',1},{'B',1}}, 0 };


```

```
string st;
st.append(to_string(c)); // c int
st.push_back(to_string(c)) // push_back() only accepts a single char // wrong
```

```
Option 1: define a custom hash struct
struct PairHash {
    size_t operator()(const pair<int,int>& p) const noexcept {
        return hash<long long>()(((long long)p.first << 32) ^ p.second);
    }
};

// OR
struct PairHash {
    size_t operator()(const pair<int,int>& p) const noexcept {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};


unordered_set<pair<int,int>, PairHash> vis;

vis.insert({x, y});
if (vis.count({nx, ny})) ...

Option 2: use a flattened integer key

unordered_set<int> vis;
int key = x * n + y;  // n = number of columns
vis.insert(key);
if (vis.count(nx * n + ny)) ...

Option 3: use vector<vector<bool>> (simplest in grids)
vector<vector<bool>> vis(m, vector<bool>(n, false));
if (!vis[x][y]) { vis[x][y] = true; }
```

```
// C++ cannot deduce the type of a recursive lambda declared with auto,
// because the compiler doesn’t know what dfs refers to while it’s still being defined.

auto dfs = [&](int x, int y) {
    ...
    dfs(dx, dy); // recursive call
    ...
};

Option 1 (Best): use std::function)
Explicitly declare the function type before defining the lambda.
function<void(int,int)> dfs = [&](int x, int y) {
}

Option 2: define a helper function

```

```
string val = "AB%C%AXC";
// string::npos=-1
// ✅ Correct way:
if (val.find('%') != string::npos) { // string::npos = -1 // if (val.find('%') != -1) {
    cout << "Found '%'";
}

// ❌ Your way doesn't work:
// val.find('%') == val.end()  // ERROR: find() returns size_t, not iterator

size_t pos = str.find(char);
size_t pos = str.find(substring);

Return Value:
Returns index (position) where character/substring is found
Returns string::npos if not found (npos = -1 or max size_t value)

string val = "AB%C%AXC";

size_t first = val.find('%');           // 2 (first %)
size_t second = val.find('%', first+1); // 4 (second %)

cout << first << " " << second;  // 2 4

```

#### Convert the char to string:
string text="abcd";
Option 1: Using string constructor
res += subs[string(1, text[i+1])];

// Option 2: Using string literal (if single char)
res += subs[string() + text[i+1]];

// Option 3: Using substr
res += subs[text.substr(i+1, 1)];

```
for (size_t i = 0; i < text.size();) {
    i++;
}
```

```
vector<int> v = {1, 2, 3};

// ❌ Warning: comparing signed and unsigned
for (int i = 0; i < v.size(); i++) {  // v.size() returns size_t
    // ...
}

// ✅ Fix 1: Use size_t
for (size_t i = 0; i < v.size(); i++) {
    // ...
}

// ✅ Fix 2: Cast to int
for (int i = 0; i < (int)v.size(); i++) {
    // ...
}

// ✅ Fix 3: Use auto
for (auto i = 0; i < v.size(); i++) {  // auto deduces to int
    // ...
}
```