/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptrptr), right(nullptrptr) {}
 *     TreeNode(int x) : val(x), left(nullptrptr), right(nullptrptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool canDel(TreeNode*node,int target){
        if(node && node->val==target && !node->left && !node->right) return true;
        return false;
    }
    void postorder(TreeNode*root,int target){
        if(root==nullptr) return;
        postorder(root->left,target);
        postorder(root->right,target);
       if(canDel(root->left,target)){
        delete(root->left);
        root->left = nullptr;
       }
       if(canDel(root->right,target)){
        delete(root->right);
        root->right = nullptr;
       }

    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        postorder(root,target);
        if(!root->left && !root->right && root->val==target){
            return NULL;
        }
        return root;

    }
};