#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
 int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        maxPathSumHelper(root, res);
        return res;
    }

    int maxPathSumHelper(TreeNode *root, int& res){
        if(root==NULL) return 0;
        int l=maxPathSumHelper(root->left, res);
        int r=maxPathSumHelper(root->right, res);
        int s=max(max(l,r)+root->val, root->val);
        int p=max(s, l+r+root->val);
        res=max(p, res);
        return s;
    }
};