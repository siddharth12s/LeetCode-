class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        int m=2*k;
        int dp[n+1][m+1];
        
        for(auto i=0;i<=m;i++)
            dp[n][i]=0;
        for(auto i=0;i<=n;i++)
            dp[i][m]=0;
        
        for(auto i=n-1;i>=0;i--){
            for(auto j=m-1;j>=0;j--){
                if(j%2==0)
                    dp[i][j]=max(-prices[i]+dp[i+1][j+1],dp[i+1][j]);
                else
                    dp[i][j]=max(prices[i]+dp[i+1][j+1],dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};
