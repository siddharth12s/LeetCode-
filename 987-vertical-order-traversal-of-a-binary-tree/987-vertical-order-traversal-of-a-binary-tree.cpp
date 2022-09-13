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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> m;
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        
        
        int hd=0;
        int level=0;
        queue<pair<TreeNode* ,pair<int,int>>> q;
        q.push({root,{hd,level}});
        
        
        while(!q.empty()){
            auto temp = q.front();
            hd= temp.second.first;
            TreeNode* f = temp.first;
            level = temp.second.second;
            q.pop();
            
            m[hd].push_back({level,f->val});
            
            if(f->left) q.push({f->left,{hd-1,level+1}});
            if(f->right)    q.push({f->right,{hd+1,level+1}});
        }
        for(auto elem : m){
            sort(elem.second.begin(),elem.second.end());
            vector<int> t;
            for(auto x : elem.second){
                t.push_back(x.second);
            }
            ans.push_back(t);
        }
        return ans;
    }
};