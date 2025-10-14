In C++, a struct is just like a class, except for one default:

All members are public by default in a struct.

All members are private by default in a class.

```
struct GNode {
    // All members are public by default
    unordered_map<char, GNode*> child;
    bool isWord = false;
    ~GNode() {
        for (auto &kv : child) delete kv.second;
    }
};

```

```
class GNode {
public:
    unordered_map<char, GNode*> child;
    bool isWord = false;
    ~GNode() {
        for (auto &kv : child) delete kv.second;
    }
};

```

```
class GNode {
    // All members are private by default
    unordered_map<char, GNode*> child;
    bool isWord = false;
    ~GNode() {
        for (auto &kv : child) delete kv.second;
    }
};

```

```
boost library // LC does not support
// array initialization
int count[26] = {0};
// s string
for (char c : s); 
vector<vector<string>>
vector<string>& strs
string& s 

sort(str.begin(),str.end());

unordered_map<string,vector<string>> um;
for(const auto& p:um){
  ans.push_back(p.second);
}
```