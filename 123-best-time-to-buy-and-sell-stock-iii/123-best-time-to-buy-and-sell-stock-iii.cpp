class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp[n+1][5];
        
        for(auto i=0;i<5;i++)
            dp[n][i]=0;
        for(auto i=0;i<=n;i++)
            dp[i][4]=0;
        
        for(auto i=n-1;i>=0;i--){
            for(auto j=3;j>=0;j--){
                if(j%2==0)
                    dp[i][j]=max(-prices[i]+dp[i+1][j+1],dp[i+1][j]);
                else
                    dp[i][j]=max(prices[i]+dp[i+1][j+1],dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};