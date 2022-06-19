class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n =matrix.size();
        int m =matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int> (m,0));
        
        for(auto i=0;i<m;i++){
            dp[0][i]=matrix[0][i];
        }
        for(auto i=0;i<n;i++){
            dp[i][0]=matrix[i][0];
        }
        
        for(auto i=1;i<n;i++){
            for(auto j=1;j<m;j++){
                if(matrix[i][j]==1)
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;
            }
        }
        int ans=0;
        for(auto i=0;i<n;i++){
            for(auto j=0;j<m;j++){
                ans+=dp[i][j];
            }
        }
        
        return ans;
    }
};