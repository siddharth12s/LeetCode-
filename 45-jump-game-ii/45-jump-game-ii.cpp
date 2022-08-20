class Solution {
public:
    int f(vector<int>& nums, int i,int dest,vector<int>& dp){
        if(i>=dest) return 0;
        int tmp = 1e9;
        if(dp[i]!=-1)   return dp[i];
        for(int jump = 1;jump<=nums[i]; jump++){
           tmp = min(tmp,1+f(nums,i+jump,dest,dp)); 
        }
        return dp[i]=tmp;
    }
    int jump(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int> dp(n+1,-1);
        return f(nums,0,n,dp);
        
    }
};