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
    void helper(TreeNode* root, int & sum,int &n,int & avg){
        if(root==NULL)
            return;
        
        if(root->left==NULL and root->right==NULL){
            sum+=root->val;
            n+=1;
            avg=sum/n;
            return;
        }
        
        sum+= root->val;
        n+=1;
        avg=sum/n;
        helper(root->left,sum,n,avg);
        helper(root->right,sum,n,avg);
        return;        
    }
    
    void dfs(TreeNode* root,int &count){
        if(root==NULL)
            return;
        int sum=0;
        int n=0;
        int avg=0;
        helper(root,sum,n,avg);
        if(avg==root->val)
            count++;
        
        dfs(root->left,count);
        dfs(root->right,count);
    }
    int averageOfSubtree(TreeNode* root) {
        int count=0;
        dfs(root,count);
        return count;
    }
};