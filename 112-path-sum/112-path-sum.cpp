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
        
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return false;
        
        if(!root->left and !root->right){
            if(targetSum==root->val)
                return true;
            return false;
        }
        
        bool ls= hasPathSum(root->left,targetSum-root->val);
        if(ls)  return true;
        bool rs= hasPathSum(root->right,targetSum-root->val);
        if(rs)  return true;
        
        return false;
    }
};