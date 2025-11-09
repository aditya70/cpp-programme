#### Incorrect ways
```
struct Trie {
    unordered_map<char, Trie*> child;
    bool isEnd;
};

class Solution {
    Trie* root = new Trie();
};

root->child  // ✅ empty unordered_map
root->isEnd  // ⚠️ uninitialized, could be true or false randomly

```

#### Correct ways

```
Option 1: Add an in-class initializer
struct Trie {
    unordered_map<char, Trie*> child;
    bool isEnd = false;  // ✅ safely initialized
};

Option 2: Write an explicit constructor
struct Trie {
    unordered_map<char, Trie*> child;
    bool isEnd;
    Trie() : isEnd(false) {}  // ✅ default constructor sets value
};


Either approach ensures that after:

Trie* root = new Trie();


you have:

root->child == {}     // empty map
root->isEnd  == false // predictable

```