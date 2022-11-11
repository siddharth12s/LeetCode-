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
    TreeNode* minVal(TreeNode* root){
        TreeNode* temp = root;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return NULL;
        
        if(root->val==key){
            
            //0 children
            if(!root->left and !root->right){
                delete root;
                return NULL;
            }
            //1 children
            
            //left side
            else if(root->left and !root->right){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            
            //right side
            else if(!root->left and root->right){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            
            //2 children
            else{
                TreeNode* mini = minVal(root->right);
                root->val=mini->val;
                root->right = deleteNode(root->right,mini->val);
                return root;
            }
        }
        
        else if(root->val>key){
            root->left= deleteNode(root->left,key);
        }
        else{
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
};