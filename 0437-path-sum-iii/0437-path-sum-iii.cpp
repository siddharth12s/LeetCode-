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
    void solve(TreeNode* root,int &count, int k, vector<long long> path){
        
        if(root==NULL)   
            return;
        
        path.push_back(root->val);
        
        solve(root->left,count,k,path);
        solve(root->right,count,k,path);
        
        long long sum=0;
        long long size=path.size();
        for(auto i= size-1;i>=0;i--){
            sum+= path[i];
            if(sum==k)
                count++;
        }
        
        path.pop_back();

    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<long long> path;
        int count = 0;
        solve(root,count,targetSum,path);
        return count;
    }
};