class Solution {
public:
    bool isMatch(string s, string p) {
        int n=p.size();
        int m=s.size();
        vector<vector<bool>> dp(n+1,vector<bool> (m+1,false));
        dp[0][0]=true;
        
        for(auto j=1;j<=m;j++)   
            dp[0][j]=false;
        
        for(auto i=1;i<=n;i++){
            int flag=true;
            for(auto x=1;x<=i;x++){
                if(p[x-1]!='*'){
                    flag=false;
                    break;
                }
            }
            dp[i][0]=flag;
        }
        
        for(auto i=1;i<=n;i++){
            for(auto j=1;j<=m;j++){
                if((p[i-1]==s[j-1])  or  (p[i-1]=='?'))
                {    dp[i][j]=dp[i-1][j-1];       }
                else if(p[i-1]=='*')
                {    dp[i][j]=(dp[i-1][j] | dp[i][j-1]); }
                else 
                {   dp[i][j]=false;  }
            }
        }
        
        return dp[n][m];
    }
};