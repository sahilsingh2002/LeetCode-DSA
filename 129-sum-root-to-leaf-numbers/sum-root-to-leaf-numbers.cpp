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
class Solution {
    int solve(TreeNode*root,int A){
        if(!root) return 0;
        A*=10;
        A+=(root->val);
        if(!root->left && !root->right) return A;
        return solve(root->left,A) + solve(root->right,A);
    }
public:
    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};