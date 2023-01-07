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
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
        while(!q.empty()){
            v.clear();
            int l=q.size();
            for(int i=0;i<l;i++){
                TreeNode* f=q.front();
                q.pop();
                v.push_back(f->val);
                if(f->left != NULL) q.push(f->left);
                if(f->right != NULL) q.push(f->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};