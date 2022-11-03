class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &nums,vector<int> &t,int i,int n,int k){
        
        if(i==n){
            if(t.size()==k){
                ans.push_back(t);
                return;
            }
            return;
        }
        
        t.push_back(nums[i]);
        solve(ans,nums,t,i+1,n,k);
        t.pop_back();
        solve(ans,nums,t,i+1,n,k);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for(auto i=1;i<=n;i++)
            nums.push_back(i);
        
        vector<vector<int>> ans;
        vector<int> t;
        solve(ans,nums,t,0,n,k);
        return ans;
    }
};