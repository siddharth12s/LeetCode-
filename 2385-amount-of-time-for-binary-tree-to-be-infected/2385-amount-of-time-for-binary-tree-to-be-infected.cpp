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
    TreeNode* buildmap(TreeNode* root,int t,unordered_map<TreeNode*, TreeNode*> &nodeToParent){
        
        TreeNode* target = NULL;
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root]=NULL;
        
        while(!q.empty()){
            TreeNode* f = q.front();
            q.pop();
            
            if(f->val==t){
                target = f;
            }
            
            if(f->left){
                q.push(f->left);
                nodeToParent[f->left]= f;
            }
            
            if(f->right){
                q.push(f->right);
                nodeToParent[f->right]=f;
            }
        }
        return target;
    }
    
    int solve(TreeNode* root,unordered_map<TreeNode*, TreeNode*> &nodeToParent){
        
        unordered_map<TreeNode* , bool> vis;
        queue<TreeNode*> q;
        q.push(root);
        vis[root]=1;
        
        
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            int flag=0;
            for(auto i=0;i<size;i++){
                
                auto f = q.front();
                q.pop();
                
                
                if(f->left and !vis[f->left]){
                    flag=1;
                    q.push(f->left);
                    vis[f->left]=1;
                }
                
                if(f->right and !vis[f->right]){
                    flag=1;
                    q.push(f->right);
                    vis[f->right]=1;
                }
                
                if(nodeToParent[f] and !vis[nodeToParent[f]]){
                    flag=1;
                    q.push(nodeToParent[f]);
                    vis[nodeToParent[f]]=1;
                }
            }
            
            if(flag)
                ans++;
        }
        return ans;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<TreeNode*, TreeNode*> nodeToParent;
        TreeNode* target = buildmap(root,start,nodeToParent);
        int ans = solve(target,nodeToParent);
        return ans;
    }
};