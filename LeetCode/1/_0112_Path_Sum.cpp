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
    bool found=false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        pathSumUtil(root, targetSum, 0);
        return found;
    }

    void pathSumUtil(TreeNode* root, int targetSum, int sum){
        if(root==NULL) return;
        sum += root->val;
        if(root->left==NULL && root->right==NULL) {
            if(targetSum==sum) {
                found=true;
                return;
            }
        }
        pathSumUtil(root->left, targetSum, sum);
        pathSumUtil(root->right, targetSum, sum);
    }
};