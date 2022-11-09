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
    void dfs(TreeNode* root,unordered_map<int,int> &m,int &ans){
        
        if(root==NULL)
            return;
        
        m[root->val]++;
        
        if(!root->left and !root->right){
            int i = 0;
            for(auto x : m){
                if(x.second%2==1){
                    i++;
                }
            }
            
            if(i<=1){
                ans++;
            }
            // return;
        }
        
        dfs(root->left,m,ans);
        dfs(root->right,m,ans);
        m[root->val]--;
        return;            
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        // vector<int> t;
        unordered_map<int,int> m;
        int ans=0;
        dfs(root,m,ans);
        
        return ans;
    }
};