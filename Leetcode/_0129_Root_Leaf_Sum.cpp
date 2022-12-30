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
        int num=0,sum=0;
        sumUtil(root,num,sum);
        return sum;
    }

    void sumUtil(TreeNode* root, int num, int &sum){
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL){
            num = num*10 + root->val;
            sum+=num;
        }
        num = num*10 + root->val;
        sumUtil(root->left, num, sum);
        sumUtil(root->right, num, sum);
    }
};