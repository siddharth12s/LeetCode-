class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<double>> dp(n+1,vector<double> (m+1,0));
        for(auto i=0;i<=n;i++) dp[i][0]=1;        
   //     for(auto i=0;i<=m;i++) dp[0][i]=0;
        dp[0][0]=1;
        
        for(auto i=1;i<=n;i++){
            for(auto j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
      /*  for(auto i=0;i<=n;i++){
            for(auto j=0;j<=m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return (int)dp[n][m];
    }
};