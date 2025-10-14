vector<int> v(n, 0);
vector<vector<bool>> dp(n, vector<bool>(n, false));
v.empty() // empty vector


vector<int> memo;
memo.assign(n + 1, -1); // initialize with -1

vector<int>& coins

const int INF = 1e9;  // big enough 
vector<int> dp(amount + 1, INF);

// dp table of size (m+1) × (n+1), initialized to 0
vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

// dp table m × n
vector<vector<long long>> dp(m, vector<long long>(n, 0));

queue<pair<int,int>> q;
q.push({si, sj});
int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
auto [i, j] = q.front();
for (auto &d : dirs) { }

unordered_set<int> s;
s.reserve(nums.size()); // allocate size of set
for (int x : s) { } // loop through the set

use of vector<int> inside the queue is very slow
queue<vector<int>> q;
use queue<pair<int,int>> q; instead

int n; // n graph nodes in undirected graph
vector<vector<int>>& edges
vector<vector<int>> adj(n);
vector<bool> visited(n, false);
```
for (auto &e : edges) {
    int u = e[0], v = e[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
}
```
void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) { }

// static in the recursion will not create every time
static vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
// auto& i.e. with the reference is more efficient
// auto without refernece makes a copy every time and less efficient
for(auto& [x,y]:dirs){ }

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

if (root==NULL)
if(root ==nullptr)
if(root) // root not NULL
if(!root) // root is NULL

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
    }
};

vector<vector<int>> Solution::levelOrder(TreeNode* root) {

}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
    }
};

// cnt and ans by reference so that changes persist across recursive calls.
// int kthSmallest(TreeNode* root, int k) { dfs(root, k, cnt, ans); }
void dfs(TreeNode* node, int k, int& cnt, int& ans) { }

// Tree by reference
bool isValidBST(TreeNode* root) {  TreeNode* prev=NULL; return isValidBSTUtil(root, prev);}
bool isValidBSTUtil(TreeNode* root, TreeNode*& prev){ }


INT_MAX // 2147483647
INT_MIN // -2147483648
LONG_MAX
LONG_MIN
LLONG_MAX, LLONG_MIN   // from <climits>
numeric_limits<long long>::max()
numeric_limits<int>::max() // same as INT_MAX
numeric_limits<int>::min() // same as INT_MIN
numeric_limits<double>::max() // 
numeric_limits<long long>::min() // same as LLONG_MIN

Time: O(n) — each node visited once
Space: O(h) where h = height of the tree (recursion stack). Worst case skewed tree: O(n), best case balanced: O(log n).

// Step 1: build graph nodes and initialize in-degrees
unordered_map<char, unordered_set<char>> graph;
unordered_map<char, int> indegree;
indegree.count(c) // character c is present or not in the set
for (auto &p : indegree) { } // loop map
```
if (!graph.count(c)) {
 graph[c] = unordered_set<char>();
}
```

string result;
result.push_back(c);