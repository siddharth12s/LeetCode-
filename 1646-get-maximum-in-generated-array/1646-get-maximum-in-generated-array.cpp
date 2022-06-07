class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n<=1)
            return n;
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        for(auto i=2;i<=n;i++){
            if(i%2)
                dp[i]=dp[i/2]+dp[(i+1)/2];
            else
                dp[i]=dp[i/2];
        }
        sort(dp.begin(),dp.end());
        return dp[n];
    }
};