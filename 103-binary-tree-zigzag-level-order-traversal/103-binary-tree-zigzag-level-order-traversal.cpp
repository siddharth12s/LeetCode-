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
        
        int ls=height(root->left)+1;
        int rs=height(root->right)+1;
        
        return max(ls,rs);
    }
    void lotRL(TreeNode* root,int k,vector<int> &t){
        
        if(root==NULL)
            return;
        
        if(k==1){
            t.push_back(root->val);
            return;
        }
        
        lotRL(root->right,k-1,t);
        lotRL(root->left,k-1,t);
        return;
    }
    void lotLR(TreeNode* root,int k,vector<int> &t){
        
        if(root==NULL)
            return;
        
        if(k==1){
            t.push_back(root->val);
            return;
        }
        
        lotLR(root->left,k-1,t);
        lotLR(root->right,k-1,t);
        return;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int h = height(root);
        vector<vector<int>> ans;
        int flag=0;
        for(auto i=1;i<=h;i++){
            vector<int> t;
            if(flag==1){
                lotRL(root,i,t);
                flag=0;
            }
            else if(flag==0){
                lotLR(root,i,t);
                flag=1;
            }
            ans.push_back(t);
        }      
        return ans;
    }
};