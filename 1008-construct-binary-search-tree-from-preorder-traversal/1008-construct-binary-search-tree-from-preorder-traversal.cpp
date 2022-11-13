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
    TreeNode* solve(int mini,int maxi,vector<int>& pre,int &i){
        if(i>=pre.size())
            return NULL;
        
        if(pre[i]<mini or pre[i]>maxi)
            return NULL;
        
        TreeNode* root = new TreeNode(pre[i++]);
        root->left= solve(mini,root->val,pre,i);
        root->right= solve(root->val,maxi,pre,i);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int mini=INT_MIN;
        int maxi=INT_MAX;
        int i=0;
        return solve(mini,maxi,pre,i);
    }
};