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
    int posty(TreeNode*root,TreeNode*par){
       if(root==NULL) return 0;
       int run = posty(root->left,root)+posty(root->right,root);
       int coins = root->val-1;
       if(par) par->val+=coins;
       run+=abs(coins);
       return run;
    }
public:
    int distributeCoins(TreeNode* root) {
        return posty(root,NULL);
    }
};