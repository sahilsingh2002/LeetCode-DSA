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
    bool postorder(TreeNode*root){
        if(root==NULL) return 0;
        
        if(root->val==1){
            return true;
        }
        else if(root->val==0){
            return false;
        }
        bool a = postorder(root->left);
        bool b = postorder(root->right);
        if(root->val==2){
            return a | b;
        }
        if(root->val==3){
            return a & b;
        }
        return false;
    }
public:
    bool evaluateTree(TreeNode* root) {
        return postorder(root);
    }
};