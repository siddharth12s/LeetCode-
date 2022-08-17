class Solution {
public:

    int integerBreak(int n) {
        
        if(n<=2)
            return 1;
        
        vector<int> dp(n+1,1);
        for(auto i=3;i<=n;i++){
            for(auto j=1;j<i;j++)
                dp[i]=max(dp[i],max(dp[i-j]*dp[j],max(dp[i-j]*j,(i-j)*j)));
        }
        return dp[n];
    }
};