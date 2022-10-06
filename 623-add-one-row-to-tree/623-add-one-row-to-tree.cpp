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
    void dfs(TreeNode* root,int d,int k,int v){
        if(root==NULL)
            return;
        
        if(k==d-1){
            TreeNode* l = new TreeNode(v);
            l->left=root->left;
            root->left=l;
            TreeNode* r = new TreeNode(v);
            r->right=root->right;
            root->right=r;
            return;
        }
        
        dfs(root->left,d,k+1,v);
        dfs(root->right,d,k+1,v);
        
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node = new TreeNode(val);
            node->left=root;
            node->right=NULL;
            return node;
        }
        else
            dfs(root,depth,1,val);
        return root;
    }
};