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
    void dfs(TreeNode* root,int sum,vector<int> &path, vector<vector<int>> & paths){
        if(root==NULL)
            return;
        path.push_back(root->val);
        if(!(root->left) and !(root->right) and sum==root->val){
            paths.push_back(path);
        }
        dfs(root->left,sum-root->val,path,paths);
        dfs(root->right,sum-root->val,path,paths);
        path.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> paths;
        dfs(root,targetSum,path,paths);
        return paths;
    }
};