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

    TreeNode* reverseOddLevels(TreeNode* root) {
        
        if(!root)   return nullptr;
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> values;
        int level=0;
        
        while(!q.empty()){
            vector<int> temp;
            int n = q.size();
            
            
            
            for(auto i=0;i<n;i++){
                TreeNode* f =  q.front();
            q.pop();
                if(level%2){
                    f->val=values[n-i-1];
                }
                
                if(f->left){
                    q.push(f->left);
                    temp.push_back(f->left->val);
                }
                
                if(f->right){
                    q.push(f->right);
                    temp.push_back(f->right->val);
                }
            }
            //values.clear();
            values=temp;
            level++;
        }
        return root;
    }
};