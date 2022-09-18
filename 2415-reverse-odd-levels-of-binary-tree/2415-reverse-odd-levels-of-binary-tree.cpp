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
    void rev(TreeNode* l,TreeNode* r,int level){
        if(l==NULL and r==NULL)
            return;
        
        if(level%2==0){
            swap(l->val,r->val);
        }
        
        rev(l->left,r->right,level+1);
        rev(l->right,r->left,level+1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        rev(root->left,root->right,0);
        return root;
        
    }
};