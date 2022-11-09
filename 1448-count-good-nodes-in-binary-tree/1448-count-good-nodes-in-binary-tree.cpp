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
    void dfs(TreeNode* root,int &ans,int cur){
        if(root==NULL)
            return;
        
        if(root->val>=cur){
            ans++;
            cur=root->val;
        }
        
        dfs(root->left,ans,cur);
        dfs(root->right,ans,cur);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        dfs(root,ans,root->val);
        return ans;
    }
};