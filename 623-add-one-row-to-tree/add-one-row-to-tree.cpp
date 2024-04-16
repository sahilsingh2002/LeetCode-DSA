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
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth ==1){
            TreeNode*main = new TreeNode(val);
            main->left = root;
            return main;

        }
        queue<TreeNode*>q;
        int idx = 1;
        q.push(root);

        while(idx<depth-1){
            int cnt = q.size();
            while(cnt>0){
                TreeNode*top = q.front();
                q.pop();
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
                cnt--;
            }
            idx++;
        }
        
        while(!q.empty()){
            TreeNode*top = q.front();
            q.pop();
            TreeNode*lefter = top->left;
            TreeNode*righter = top->right;

            TreeNode*lefto = new TreeNode(val);
            TreeNode*righto = new TreeNode(val);
            top->left = lefto;
            top->right = righto;
            lefto->left = lefter;
            righto->right=righter;
        }
        return root;
    }
};