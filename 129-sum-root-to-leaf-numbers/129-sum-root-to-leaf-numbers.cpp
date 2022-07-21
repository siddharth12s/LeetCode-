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
    void help(TreeNode* root, vector<int> & no, int n){
        if(root==NULL)  return;
        if(!root->left and !root->right){
            n = n*10 + root->val;
            no.push_back(n);
            return;
        }
        
        n = n*10 + root->val;
        help(root->left,no,n);
        help(root->right,no,n);
        return;
    }
    int sumNumbers(TreeNode* root) {
        vector<int> no;
        if(root==NULL)  return 0;
        help(root,no,0);
        int ans=0;
        for(auto i=0;i<no.size();i++)
            ans += no[i];
        
        return ans;
    }
};