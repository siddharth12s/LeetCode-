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
    void num(TreeNode* root,vector<int> &v,int n){
        
        if(root==NULL)
            return;
        if(root->left==NULL and root->right==NULL){
            v.push_back(n*2 + root->val);
            return;
        }
        
        num(root->left,v,n*2+root->val);
        num(root->right,v,n*2+root->val);
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<int> v;
        num(root,v,0);
        int sum=0;
        for(auto i=0;i<v.size();i++){
          sum+=v[i];
        }
        
        return sum;
    }
};