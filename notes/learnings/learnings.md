
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