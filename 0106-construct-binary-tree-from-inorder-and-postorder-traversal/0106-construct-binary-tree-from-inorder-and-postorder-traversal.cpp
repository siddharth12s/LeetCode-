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
     TreeNode* solve(vector<int> &post,vector<int> &ino, int &index,int inoStart, int inoEnd, int n,unordered_map<int,int> &m){
        
        if(index<0 or inoStart> inoEnd){
            return nullptr;
        }
        
        int elem = post[index--];
        TreeNode* root = new TreeNode(elem);
        int pos = m[elem];
        
        root->right = solve(post,ino,index,pos+1,inoEnd,n,m);
        root->left = solve(post,ino,index,inoStart,pos-1,n,m);
        
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int,int> m;
        for(auto i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        int postIndex=n-1;
        TreeNode* ans = solve(postorder,inorder,postIndex,0,n-1,n,m);
        return ans;
    }
};