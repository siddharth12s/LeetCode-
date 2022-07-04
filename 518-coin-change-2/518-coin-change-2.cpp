class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        
        vector<int> dp(amount+1,0);
        dp[0]=1;
        for(auto c : coins){
            for(auto i=1;i<=amount;i++){
                if(i-c>=0)
                    dp[i] += dp[i-c];
            }
        }
        for(auto i=0;i<=amount;i++){
            cout<<dp[i]<<" ";
        }
        return dp[amount];
    }
};