class Solution {
public:   
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
       // vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
        vector<int> prev(m+1,0),cur(m+1,0);
        for(auto i=0;i<=m;i++)
            prev[i]=0;
     //   for(auto i=0;i<=m;i++)
       //     dp[0][i]=0;
        for(auto i=1;i<n+1;i++){
            for(auto j=1;j<m+1;j++){
                if(text1[i-1]==text2[j-1])  cur[j] = prev[j-1] + 1;
                else
                    cur[j]= max(prev[j],cur[j-1]);
            }
            prev = cur;
        }
        return prev[m];
    }
};