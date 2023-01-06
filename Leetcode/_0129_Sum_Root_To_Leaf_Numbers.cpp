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
  int sumNumbers(TreeNode* root) {
        int sum=0;
        sumUtil(root, 0, sum);
        return sum;
    }

    void sumUtil(TreeNode* root, int s, int& sum){
        if(root==NULL) return;
        s=s*10+root->val;
        if(root->left==NULL && root->right==NULL) sum+=s;
        sumUtil(root->left, s, sum);
        sumUtil(root->right, s, sum);
    }
};