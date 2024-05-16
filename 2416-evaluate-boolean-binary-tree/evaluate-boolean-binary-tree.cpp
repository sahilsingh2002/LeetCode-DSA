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
    bool evaluateNode(TreeNode* node) {
        if (node == nullptr) 
            return false;
        
        if (node->val == 1) 
            return true;
        
        if (node->val == 0) 
            return false;
        
        bool leftResult = evaluateNode(node->left);
        bool rightResult = evaluateNode(node->right);
        
        return node->val == 2 ? leftResult || rightResult : leftResult && rightResult;
    }
public:
    bool evaluateTree(TreeNode* root) {
        return evaluateNode(root);
    }
};