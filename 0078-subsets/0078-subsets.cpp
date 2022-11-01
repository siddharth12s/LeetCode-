class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int>& nums,vector<int> &t,int i,int n){
        
        if(i==n){
            ans.push_back(t);
            return;
        }
        
        t.push_back(nums[i]);
        solve(ans,nums,t,i+1,n);
        t.pop_back();
        solve(ans,nums,t,i+1,n);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> t;
        int n= nums.size();
        solve(ans,nums,t,0,n);
        return ans;
    }
};