class Solution {
public:
//     int f(vector<vector<int>> &dp,int i,int j){
//         if(i==0 and j==0)   return 1;
//         if(i<0 or j<0)  return 0;
        
//         if(dp[i][j]!=-1)    return dp[i][j];
        
//         int up = f(dp,i-1,j);
//         int left =  f(dp,i,j-1);
        
//         return dp[i][j]=up + left;
//     }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[1][1]=1;
        
        for(auto i=0;i<=m;i++)
            dp[i][0]=1;
        for(auto i=0;i<=n;i++)
            dp[0][i]=1;
        
        for(auto i=1;i<m;i++){
            for(auto j=1;j<n;j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};