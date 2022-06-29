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
    TreeNode* build(vector<int> &a,int s,int e){
        if(s>e)
            return NULL;
        
        int maxi=-1;
        int p=-1;
        for(auto i=s;i<=e;i++){
           if(a[i]>=maxi){
               maxi=a[i];
               p=i;
           }
        }
        // if(maxi==INT_MIN)
        //     return NULL;
        TreeNode* root = new TreeNode(maxi);
        root->left = build(a,s,p-1);
        root->right = build(a,p+1,e);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
       return build(nums,0,nums.size()-1);
    }
};