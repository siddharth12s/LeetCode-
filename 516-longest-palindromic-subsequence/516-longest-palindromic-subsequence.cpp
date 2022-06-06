class Solution {
public:
    int lcs(int a, int b,string s,string t,vector<vector<int>> &dp){
        vector<int> prev(a+1,0),cur(b+1,0);
     //   for(auto i=0;i<=a;i++)
       //     dp[i][0]=0;
        for(auto i=0;i<=b;i++)
            prev[i]=0;
        
        
        for(auto i=1;i<=a;i++){
            for(auto j=1;j<=b;j++){
                if(s[i-1]==t[j-1])
                    cur[j]=1 + prev[j-1];
                else
                    cur[j]= max(prev[j],cur[j-1]);
            }
            prev=cur;
        }
        
        return prev[b];
    }
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n = s.length();
        int m=n;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return lcs(n,m,s,s2,dp);
    }
};