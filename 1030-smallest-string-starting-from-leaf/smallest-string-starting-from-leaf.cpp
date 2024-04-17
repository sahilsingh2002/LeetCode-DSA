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
    void inorder(TreeNode*root,string A,vector<string>&ans){
        if(!root) return;
        if(!root->left && !root->right){
             char c = 'a'+root->val;
               A=c+A;
           if(A.size()>0) ans.push_back(A);
           return;
        }
        char c = 'a'+root->val;
        A=c+A;
        inorder(root->left,A,ans);
        inorder(root->right,A,ans);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        vector<string>ans;
        inorder(root,"",ans);
        string m = ans[0];
        for(string i:ans){
            m = min(i,m);
        }
        return m;
    }
};