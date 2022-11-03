class Solution {
public:
    void solve(vector<vector<int>> &ans, set<vector<int>> &s, vector<int>& nums,int i,int n){
        
        if(i==n){
            if(s.count(nums)==0){
                s.insert(nums);
                ans.push_back(nums);
                return;
            }
            return;
        }
        
        for(auto j=i;j<n;j++){
            swap(nums[i],nums[j]);
            solve(ans,s,nums,i+1,n);
            swap(nums[i],nums[j]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n=nums.size();
        solve(ans,s,nums,0,n);
        return ans;
    }
};