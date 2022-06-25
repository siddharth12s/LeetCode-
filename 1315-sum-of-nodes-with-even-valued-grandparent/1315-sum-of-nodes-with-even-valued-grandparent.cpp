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
    void dfs(TreeNode* cur, TreeNode* parent, TreeNode* grandparent,int & sum){
        if(cur==NULL)  return;
        
        if(grandparent!=NULL and grandparent->val%2==0)
            sum += cur->val;
        
        dfs(cur->left,cur,parent,sum);
        dfs(cur->right,cur,parent,sum);
        return;
    }
    int sumEvenGrandparent(TreeNode* root) {
         int sum=0;
        dfs(root,nullptr,nullptr,sum);
        return sum;
    }
};