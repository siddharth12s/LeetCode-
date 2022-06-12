class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,0));
        dp[n][0]= dp[n][1]=0;
        for(auto i=n-1;i>=0;i--){
            for(auto j=0;j<2;j++){
                if(j)
                    dp[i][j]=max(-prices[i] + dp[i+1][0],dp[i+1][1]);
                else
                    dp[i][j]=max(prices[i]-fee+dp[i+1][1],dp[i+1][0]);
            }
        }
        return dp[0][1];
    }
};