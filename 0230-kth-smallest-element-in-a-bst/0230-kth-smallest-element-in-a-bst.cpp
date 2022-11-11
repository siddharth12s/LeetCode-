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
    void dfs(TreeNode* root,int &cnt,int k,int &ans){
        if(root==NULL){
            return;
        }
        
        dfs(root->left,cnt,k,ans);
        cnt++;
        if(cnt==k){
            ans=root->val;
            return;
        }
        
        dfs(root->right,cnt,k,ans);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        int ans=-1;
        dfs(root,cnt,k,ans);
        return ans;
    }
};