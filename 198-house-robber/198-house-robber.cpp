class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        for(auto i=1;i<n;i++){
            int pick = nums[i];
            if(i-2>=0)  pick+=dp[i-2];
            int notpick = dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
    }
};