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
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        
        if(!root->left and !root->right)
            return;
        
        TreeNode* cur = root;
        TreeNode* pre;
        
        while(cur!=NULL){
            if(cur->left){
                pre= cur->left;
                while(pre->right!=NULL){
                    pre=pre->right;
                }
                
                pre->right=cur->right;
                cur->right=cur->left;
            }
            cur=cur->right;
        }
        cur=root;
        while(cur!=NULL){
            cur->left=NULL;
            cur=cur->right;
        }
    }
};