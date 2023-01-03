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
    void pathUtil(TreeNode *root, vector<int> a, vector<string>& v){
        if(!root) return;
        a.push_back(root->val);
        if (root->left == NULL && root->right == NULL){
            string s="";
            for(int i=0;i<a.size()-1;i++){
                s+=to_string(a[i]);
                s+="->";
            }
            if(a.size()>0){
                s+=to_string(a[a.size()-1]);
                v.push_back(s);
            }
            return;
        }
        pathUtil(root->left, a, v);
        pathUtil(root->right, a, v);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> a;
        pathUtil(root, a, ans);
        return ans;    
    }
};