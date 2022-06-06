class Solution {
public:
    int lcs(int a, int b,string s,string t,vector<vector<int>> &dp){
        for(auto i=0;i<=a;i++)
            dp[i][0]=0;
        for(auto i=0;i<=b;i++)
            dp[0][i]=0;
        
        
        for(auto i=1;i<=a;i++)
            for(auto j=1;j<=b;j++)
                if(s[i-1]==t[j-1])
                    dp[i][j]=1 + dp[i-1][j-1];
                else
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
        
        return dp[a][b];
    }
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n = s.length();
        int m=n;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return lcs(n,m,s,s2,dp);
    }
};