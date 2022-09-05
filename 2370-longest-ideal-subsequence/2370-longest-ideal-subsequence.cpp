class Solution {
public:

    int longestIdealString(string s, int k) {
        vector<int> dp(26,0);
        
        for(auto &ch : s){
            int i = ch-'a';
            dp[i]++;
            
            for(auto j=max(0,i-k);j<= min(25,i+k);j++){
                if(j!=i)
                    dp[i]=max(dp[i],dp[j]+1);
            }
        }
        
        int ans=0;
        for(auto i=0;i<26;i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};