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
    pair<int,int> helper(TreeNode* root, int & count){
        if(root==NULL)
            return {0,0};
        
        auto left = helper(root->left,count);
        auto right = helper(root->right,count);
        
        int sum = (left.first + right.first+root->val);
        int n = (left.second + right.second + 1);
        count += ((sum/n)==root->val);
        return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
        int count=0;
        helper(root,count);
        return count;
    }
};