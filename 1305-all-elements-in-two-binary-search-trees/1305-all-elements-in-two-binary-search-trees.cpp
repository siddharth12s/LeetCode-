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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        queue<TreeNode* > q;
        if(root1!=NULL){
            q.push(root1);
            while(!q.empty()){
                TreeNode* f = q.front();
                q.pop();
                ans.push_back(f->val);
                if(f->left) q.push(f->left);
                if(f->right)    q.push(f->right);
            }
        }
        if(root2!=NULL){
            q.push(root2);
           while(!q.empty()){
                TreeNode* f = q.front();
                q.pop();
                ans.push_back(f->val);
                if(f->left) q.push(f->left);
                if(f->right)    q.push(f->right);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};