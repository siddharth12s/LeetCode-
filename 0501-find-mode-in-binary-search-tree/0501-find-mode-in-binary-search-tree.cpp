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
    void dfs(TreeNode* root, unordered_map<int,int> &m){
        if(!root)   return;

        m[root->val]++;
        dfs(root->left,m);
        dfs(root->right,m);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> m;
        dfs(root,m);

        int maxi = 0;
        vector<int> ans;

        for(auto x : m){
            maxi=max(x.second,maxi);
        }

        for(auto x : m){
            if(x.second==maxi)
                ans.push_back(x.first);
        }

        return ans;
    }
};