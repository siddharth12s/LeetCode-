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
        if(!root)   return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        if(lh==-1 or rh==-1 or abs(lh-rh)>1)    return -1;
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)   return true;
        if(height(root)==-1)   return false;
        // if(>1)   return false;

        return true;
    }
};