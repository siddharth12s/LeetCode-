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
    pair<TreeNode*,int> dfs(TreeNode* root){
        if(root==NULL){
            return {NULL,0};
        }
        
        auto ls = dfs(root->left);
        auto rs =  dfs(root->right);
        
        if(ls.second>rs.second)
            return {ls.first,ls.second+1};
        if(ls.second<rs.second)
            return {rs.first,rs.second+1};
        
        return {root,ls.second+1};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};