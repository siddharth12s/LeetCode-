class Solution {
public:
    int f(int i,int j, vector<vector<int>> &a,int n,vector<vector<int>> &dp){
        if(j<0 or j>=n) return 1e9;
        
        if(i==0)    return a[0][j];
        
        if(dp[i][j]!=-1)    return dp[i][j];
        
        int s = a[i][j] + f(i-1,j,a,n,dp);
        int ld = a[i][j] + f(i-1,j-1,a,n,dp);
        int rd = a[i][j] + f(i-1,j+1,a,n,dp);
        
        return dp[i][j]= min(s,min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& a) {
        
        int m = a.size();
        int n = a[0].size();
        
        vector<vector<int>> dp(m,vector<int> (n,-1));
        int mini=1e9;
        for(auto i=0;i<n;i++){
            mini= min(mini,f(m-1,i,a,n,dp));
        }
        return mini;
    }
};