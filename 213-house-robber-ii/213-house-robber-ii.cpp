class Solution {
public:
    int f(int i,vector<int>& nums,int end,vector<int>& dp){
        if(i<end) return 0;
        
        if(dp[i]!=-1)   return dp[i];
        int pick = nums[i]+f(i-2,nums,end,dp);
        int notpick = f(i-1,nums,end,dp);
        
        return dp[i]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    return nums[0];
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);
        return max(f(n-1,nums,1,dp1),f(n-2,nums,0,dp2));
    }
};