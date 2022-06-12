class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cap=2;
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (3,0)));
        
        for(auto i=n-1;i>=0;i--){
            for(auto j=0;j<2;j++){
                for(auto k=1;k<3;k++){
                    if(j){
                        dp[i][j][k]= max(-prices[i]+dp[i+1][0][k],dp[i+1][1][k]);
                    }
                    else{
                        dp[i][j][k]=max(prices[i]+dp[i+1][1][k-1],dp[i+1][0][k]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};