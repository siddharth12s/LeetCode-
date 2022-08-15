class Solution {
public:
    bool f(vector<int> &nums,vector<vector<int>> &dp,int ind,int target){
        if(target==0)   return 1;
        if(ind==0)  return nums[0]==target;
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        bool nottake = f(nums,dp,ind-1,target);
        bool take = false;
        if(target>=nums[ind]){
            take = f(nums,dp,ind-1,target-nums[ind]);
        }
        
        return dp[ind][target]=take or nottake;
        
    }
    bool canPartition(vector<int>& nums) {
        int totsum =0;
        for(auto i=0;i<nums.size();i++)
            totsum += nums[i];
        
        if(totsum%2)    return false;
        
        vector<vector<int>> dp(nums.size(),vector<int>(totsum+1,-1));
        return f(nums,dp,nums.size()-1,totsum/2);
    }
};