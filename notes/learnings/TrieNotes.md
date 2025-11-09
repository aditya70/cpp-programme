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

#### Snippets

```
struct TrieNode {
    TrieNode* child[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        for (int k = 0; k < 26; ++k) child[k] = nullptr;
    }
};
```

```
struct Trie {
    Trie* child[26];
    // No constructor
};

Trie* node = new Trie();
// node->child[0] contains some random address, not nullptr
```

#### Correlation

```
int arr[5];  // Contains garbage values
// arr[0], arr[1], etc. have random/unpredictable values
cout << arr[0];  // Prints some random number like 12345 or -9999
Initialize with constructor/brace initialization:

cppint arr[5] = {};        // All zeros
int arr[5] = {0};       // All zeros
int arr[5]{};           // All zeros (C++11)

Initialize with specific values:

cppint arr[5] = {1, 2, 3, 4, 5};
int arr[5]{1, 2, 3, 4, 5};

For dynamic allocation:

cppint* arr = new int[5]();   // () initializes to 0
int* arr = new int[5]{};   // {} initializes to 0

Using memset (for all zeros):

arr[5];
memset(arr, 0, sizeof(arr));
```