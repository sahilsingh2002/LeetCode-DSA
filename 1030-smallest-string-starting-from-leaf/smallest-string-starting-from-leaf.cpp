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
    string inorder(TreeNode*root,string A){
        if(!root) return "zzzzzzzz";
        if(!root->left && !root->right){
             char c = 'a'+root->val;
               A=c+A;
           return A;
        }
        char c = 'a'+root->val;
        A=c+A;
        return min(inorder(root->left,A),inorder(root->right,A));
    }
public:
    string smallestFromLeaf(TreeNode* root) {
       
        string m = inorder(root,"");
        // string m = ans[0];
        // for(string i:ans){
        //     m = min(i,m);
        // }
        return m;
    }
};