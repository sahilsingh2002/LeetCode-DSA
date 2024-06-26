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
        vector<int>arr;
        void inorder(TreeNode* root){
            if(!root) return;
            inorder(root->left);
            arr.push_back(root->val);
            inorder(root->right);
        }
        TreeNode* makeTree(vector<int>&arr,int l,int r){
            if(l>r || l>=arr.size() || r<0 || l<0 || r>=arr.size()) {
                
                return NULL;
            };
            int mid = (l+r)/2;
            TreeNode*rooted = new TreeNode(arr[mid]);
            rooted->left = makeTree(arr,l,mid-1);
            rooted->right = makeTree(arr,mid+1,r);
            return rooted;
        }
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        
        TreeNode*newR = makeTree(arr,0,arr.size()-1);
        return newR;

    }
};