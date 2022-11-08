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
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        
        int ls = height(root->left)+1;
        int rs = height(root->right)+1;
        
        return max(ls,rs);
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==NULL)
            return NULL;
        
        int ld = height(root->left);
        int rd = height(root->right);
        
        if(ld==rd)
            return root;
        
        if(ld>rd)
            return lcaDeepestLeaves(root->left);
        
        return lcaDeepestLeaves(root->right);
    }
};