#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    // Each node has 26 possible children and a flag for end of word
    vector<Trie*> child;
    bool isWord;

    Trie() : child(26, nullptr), isWord(false) {}

    // Insert a word into the Trie
    void insert(const string &word) {
        Trie* node = this;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->child[idx]) 
                node->child[idx] = new Trie();
            node = node->child[idx];
        }
        node->isWord = true;
    }

    // Search for a complete word
    bool search(const string &word) {
        Trie* node = this;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->child[idx]) return false;
            node = node->child[idx];
        }
        return node->isWord;
    }

    // Check if any word starts with the given prefix
    bool startsWith(const string &prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!node->child[idx]) return false;
            node = node->child[idx];
        }
        return true;
    }

    // Remove a word from the Trie
    bool remove(const string &word, int depth = 0) {
        if (depth == word.size()) {
            if (!isWord) return false;  // word not found
            isWord = false;
            return all_of(child.begin(), child.end(), [](Trie* p){ return p == nullptr; });
        }
        int idx = word[depth] - 'a';
        if (!child[idx]) return false;

        bool shouldDeleteChild = child[idx]->remove(word, depth + 1);
        if (shouldDeleteChild) {
            delete child[idx];
            child[idx] = nullptr;
        }

        return !isWord && all_of(child.begin(), child.end(), [](Trie* p){ return p == nullptr; });
    }

    ~Trie() {
        for (Trie* node : child)
            if (node) delete node;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");

    cout << boolalpha;
    cout << "search('apple'): " << trie.search("apple") << "\n";   // true
    cout << "search('app'): "   << trie.search("app") << "\n";     // true
    cout << "startsWith('ap'): " << trie.startsWith("ap") << "\n"; // true
    trie.remove("apple");
    cout << "search('apple'): " << trie.search("apple") << "\n";   // false
    cout << "search('app'): "   << trie.search("app") << "\n";     // true
}


/*
 Trie* child[26] = {};
 Trie() {
    // Initialize all children as null and mark word flag as false
    for (int i = 0; i < 26; ++i)
        child[i] = nullptr;
    isWord = false;
}
*/

/*
class Trie {
public:
    vector<Trie*> child;
    bool isWord;

    // Option 1: initializer list
    Trie() : child(26, nullptr), isWord(false) {}

    // Option 2: resize inside constructor // creates and resize it
    // Trie() { child.resize(26, nullptr); isWord = false; }

    // Option 3: assign inside constructor - Mainly used for assign new value
    // Trie() { child.assign(26, nullptr); isWord = false; }

    // Option 4: inside constructor
    Trie() {
        child = vector<Trie*>(26, nullptr);
        isWord = false;
    }
};
*/


// using map
#include <bits/stdc++.h>
using namespace std;

struct GNode {
    unordered_map<char, GNode*> child;
    bool isWord = false;
    ~GNode() {
        for (auto &kv : child) delete kv.second;
    }
};

class GenericTrie {
public:
    GenericTrie() : root(new GNode()) {}
    ~GenericTrie() { delete root; }

    void insert(const string &s) {
        GNode* node = root;
        for (char c : s) {
            if (!node->child.count(c)) node->child[c] = new GNode();
            node = node->child[c];
        }
        node->isWord = true;
    }

    bool search(const string &s) const {
        GNode* node = findNode(s);
        return node && node->isWord;
    }

    bool startsWith(const string &prefix) const {
        return findNode(prefix) != nullptr;
    }

    bool remove(const string &s) {
        return removeRec(root, s, 0);
    }

private:
    GNode* root;

    GNode* findNode(const string &s) const {
        GNode* node = root;
        for (char c : s) {
            auto it = node->child.find(c);
            if (it == node->child.end()) return nullptr;
            node = it->second;
        }
        return node;
    }

    bool removeRec(GNode* node, const string &s, int depth) {
        if (!node) return false;
        if (depth == (int)s.size()) {
            if (!node->isWord) return false;
            node->isWord = false;
            return node->child.empty();
        }
        char c = s[depth];
        auto it = node->child.find(c);
        if (it == node->child.end()) return false;
        bool shouldDeleteChild = removeRec(it->second, s, depth + 1);
        if (shouldDeleteChild) {
            delete it->second;
            node->child.erase(it);
            return (!node->isWord && node->child.empty());
        }
        return false;
    }
};


// Memory Optmized Implementation of Trie using Array and without heap memory allocation

struct TrieNode {
    int count;
    int child[26];
    TrieNode() {
        count = 0;
        memset(child, -1, sizeof(child));
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        const int MAX_NODES = 1e6 + 10;  
        vector<TrieNode> trie(MAX_NODES);
        int nodeCount = 1; // root = 0

        // Insert words
        for (auto &word : words) {
            int node = 0;
            for (char ch : word) {
                int idx = ch - 'a';
                if (trie[node].child[idx] == -1)
                    trie[node].child[idx] = nodeCount++;
                node = trie[node].child[idx];
                trie[node].count++;
            }
        }

        // Compute prefix scores
        vector<int> ans;
        ans.reserve(words.size());
        for (auto &word : words) {
            int node = 0;
            int score = 0;
            for (char ch : word) {
                int idx = ch - 'a';
                node = trie[node].child[idx];
                score += trie[node].count;
            }
            ans.push_back(score);
        }
        return ans;
    }
};
