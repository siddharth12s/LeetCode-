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
    int height(TreeNode* root){
        if(root==nullptr)
            return 0;
        
        int lh= height(root->left);
        int rh= height(root->right);
        return max(lh,rh)+1;
    }
    
    void sumatk(TreeNode* root,int k,int &sum){
        if(root==NULL)
            return;
        
        if(!root->left and !root->right){
            if(k==1){
                sum += root->val;
                return;
            }
        }
        
        sumatk(root->left,k-1,sum);
        sumatk(root->right,k-1,sum);
        return;
    }
    int deepestLeavesSum(TreeNode* root) {
        int k=height(root);
        int sum=0;
        sumatk(root,k,sum);
        return sum;
    }
};