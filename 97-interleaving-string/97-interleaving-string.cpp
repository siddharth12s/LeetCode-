class Solution {
public:
    bool solve(string& s1, string& s2, string& s3,int i,int j,int k,vector<vector<int>> &dp){
        if(k==s3.size())    return 1;
        
        if(i<s1.size() and j<s2.size() and dp[i][j]!=-1) return dp[i][j];
        
        if(i<s1.size() and j<s2.size() and s1[i]==s3[k] and s2[j]==s3[k])
            return dp[i][j]=solve(s1,s2,s3,i+1,j,k+1,dp) or solve(s1,s2,s3,i,j+1,k+1,dp);
        
        if(i<s1.size() and s1[i]==s3[k])
            return dp[i][j]=solve(s1,s2,s3,i+1,j,k+1,dp);
        
        else if(j<s2.size() and s2[j]==s3[k])
            return dp[i][j]=solve(s1,s2,s3,i,j+1,k+1,dp);
        
        else
            return dp[i][j]=0;
        
        return dp[i][j]=1;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int o=s3.size();
        if(n+m!=o)  return 0;
        
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return solve(s1,s2,s3,0,0,0,dp);
        // return dp[n-1][m-1];
    }
};