class Solution {
public:
    
    void solve(vector<vector<int>> &ans, set<vector<int>> &s,vector<int>& nums,vector<int>& t, int i, int n){
        if(i==n){
            if(s.count(t)==0){
                s.insert(t);
                ans.push_back(t);
            }
            return;
        }
        
        t.push_back(nums[i]);
        solve(ans,s,nums,t,i+1,n);
        t.pop_back();
        solve(ans,s,nums,t,i+1,n);   
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int> t;
        
        int n= nums.size();
        solve(ans,s,nums,t,0,n);
        return ans;
    }
};