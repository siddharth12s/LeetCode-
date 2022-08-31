class Solution {
public:
    int f(int i,int j,vector<vector<int>> &a,int n,vector<vector<int>> &dp){
        if(j<0 or j>=n) return 1e9;
        
        if(i==0)    return a[0][j];
        
        if(dp[i][j]!=-1)    return dp[i][j];
        
       int ans = INT_MAX;
        for(auto k=0;k<n;k++){
            if(k==j)    continue;
            
            int cur = a[i][j] + f(i-1,k,a,n,dp);
            ans = min(ans,cur);
        }
        
        return dp[i][j]=ans;   
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        
        vector<vector<int>> dp(m,vector<int> (n,-1));
        int mini = 1e9;
        for(auto i=0;i<n;i++){
            mini = min(mini,f(m-1,i,grid,n,dp));
        }
        return mini;
    }
};