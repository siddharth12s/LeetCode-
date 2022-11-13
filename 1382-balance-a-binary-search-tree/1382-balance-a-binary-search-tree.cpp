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
    void in(TreeNode* root,vector<int> &inV){
        if(root==NULL)
            return;
        
        in(root->left,inV);
        inV.push_back(root->val);
        in(root->right,inV);
        return;
    }
    
    TreeNode* intoBST(int s,int e,vector<int> v){
        
        if(s>e){
            return NULL;
        }
        
        int m = s + (e-s)/2;
        
        TreeNode* root = new TreeNode(v[m]);
        root->left = intoBST(s,m-1,v);
        root->right = intoBST(m+1,e,v);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inV;
        
        in(root,inV);
        root= intoBST(0,inV.size()-1,inV);
        return root;
        
    }
};