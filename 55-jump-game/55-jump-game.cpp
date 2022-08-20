class Solution {
public:
    bool f(vector<int>& nums,int i,vector<int>& dp){
        if(i==nums.size()-1)    return true;
        if(nums[i]==0)  return false;
        if(dp[i]!=-1)   return dp[i];
        int dest = i + nums[i];
        for(auto jumps = i+1; jumps<= dest; jumps++){
            if(jumps<nums.size() and f(nums,jumps,dp))
                return dp[i]=true;
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(nums,0,dp);
    }
};