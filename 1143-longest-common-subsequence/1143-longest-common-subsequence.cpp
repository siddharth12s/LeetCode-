class Solution {
public:
    int f(string a, string b, int i, int j,int n,int m,vector<vector<int>> &dp){
        if(i>=n or j>=m) 
            return 0;
        
        if(dp[i][j]!=-1)    return dp[i][j];
        
        if(a[i]==b[j])
            return dp[i][j]= 1 +f(a,b,i+1,j+1,n,m,dp);
        else
            return dp[i][j]= max(f(a,b,i+1,j,n,m,dp),f(a,b,i,j+1,n,m,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(auto i=n-1;i>=0;i--){
            for(auto j=m-1;j>=0;j--){
                if(text1[i]==text2[j])
                    dp[i][j]=1 + dp[i+1][j+1];
                else
                    dp[i][j]= max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};