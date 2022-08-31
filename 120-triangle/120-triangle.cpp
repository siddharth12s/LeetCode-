class Solution {
public:
    int f(int i,int j,vector<vector<int>>& a,int n,vector<vector<int>> &dp){
        if(i==n-1)  return a[n-1][j];
        
        if(dp[i][j]!=-1)    return dp[i][j];
        int d = a[i][j] + f(i+1,j,a,n,dp);
        int rd = a[i][j] + f(i+1,j+1,a,n,dp);
        
        return dp[i][j]=min(d,rd);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        
        
        vector<vector<int>> dp(m,vector<int> (m,-1));
        int mini = f(0,0,triangle,m,dp);
        return mini;
    }
};