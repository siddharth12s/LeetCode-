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
    
    TreeNode* solve(vector<int> &pre,vector<int> &ino, int &index,int inoStart, int inoEnd, int n,unordered_map<int,int> &m){
        
        if(index>=n or inoStart> inoEnd){
            return nullptr;
        }
        
        int elem = pre[index++];
        TreeNode* root = new TreeNode(elem);
        int pos = m[elem];
        
        root->left = solve(pre,ino,index,inoStart,pos-1,n,m);
        root->right = solve(pre,ino,index,pos+1,inoEnd,n,m);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int,int> m;
        for(auto i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        int preIndex=0;
        TreeNode* ans = solve(preorder,inorder,preIndex,0,n-1,n,m);
        return ans;
    }
};