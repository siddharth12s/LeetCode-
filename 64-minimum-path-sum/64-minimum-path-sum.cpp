class Solution {
public:
    int f(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &grid){
        if(i==0 and j==0)   return grid[0][0];
        if(i<0 or j<0)  return 1e9;
        
        if(dp[i][j]!=-1)    return dp[i][j];
        
        int up= grid[i][j] + f(i-1,j,dp,grid);
        int left=grid[i][j] + f(i,j-1,dp,grid);
        return dp[i][j]=min(up,left);        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(auto i=0;i<n;i++){
            for(auto j=0;j<m;j++){
                if(i==0 and j==0)
                    dp[i][j]=grid[i][j];
                else if(i==0 and j!=0)
                    dp[i][j]=grid[i][j]+dp[i][j-1];
                else if(i!=0 and j==0)
                    dp[i][j]=grid[i][j]+dp[i-1][j];
                else
                    dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
  
    }
};