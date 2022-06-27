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
    int height( TreeNode* root){
        if(root==NULL)
            return 0;
        
        int ls=height(root->left);
        int rs=height(root->right);
        
        return max(ls,rs)+1;
    }
    void lot(TreeNode* root,int k,vector<int> &t){
        
        if(root==NULL)
            return;
        
        if(k==1){
            t.push_back(root->val);
            return;
        }
        
        lot(root->left,k-1,t);
        lot(root->right,k-1,t);
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int h = height(root);
        vector<vector<int>> ans;
        for(auto i=1;i<=h;i++){
            vector<int> t;
            lot(root,i,t);
            ans.push_back(t);
        }      
        return ans;       
    }
};