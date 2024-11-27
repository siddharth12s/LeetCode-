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
    vector<string> ans;
public:
    void dfs(TreeNode* root,string temp){
        if(!root){
            return;
        }
        if(!root->left and !root->right){
            temp += to_string(root->val);
            ans.push_back(temp);
            // for(auto i=0;i<3;i++){
            //     temp.pop_back();
            // }
            return;
        }

        temp += to_string(root->val);
        temp += "->";
        dfs(root->left,temp);
        dfs(root->right,temp);
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string temp = "";
        dfs(root,temp);
        return ans;
    }
};