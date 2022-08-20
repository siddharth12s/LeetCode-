class Solution {
public:
    int f(vector<int>& freq,int i,vector<int>& dp){
        if(i<=0) return 0; 
        
        if(dp[i]!=-1)   return dp[i];
        int take = i*freq[i] + f(freq,i-2,dp);
        int nottake = f(freq,i-1,dp);
        
        return dp[i]=max(nottake,take);
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> freq(nums[n-1]+1,0);
        for(auto i=0;i<n;i++)   freq[nums[i]]++;
        vector<int> dp(nums[n-1]+1,-1);
        return f(freq,nums[n-1],dp);
    }
};