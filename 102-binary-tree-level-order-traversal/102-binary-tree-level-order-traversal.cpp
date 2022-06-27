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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        queue<TreeNode *> q;
        vector<int> t;
        
        if(!root)   return ans;
        if(root){
            q.push(root);
            q.push(NULL);
        }
        
        while(!q.empty()){
            
            if(q.front()==NULL){
                ans.push_back(t);
                t.resize(0);
                q.pop();
                if(!q.empty())
                    q.push(NULL);
            }
            else{
                TreeNode * f=q.front();
                t.push_back(f->val);
                q.pop();
                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }
            }
        }
        return ans;       
    }
};