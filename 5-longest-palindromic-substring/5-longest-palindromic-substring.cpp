class Solution {
public:
    string lcs(int a, int b,string s,string t,vector<vector<int>> &dp){
        for(auto i=0;i<=a;i++)
            dp[i][0]=0;
        for(auto i=0;i<=b;i++)
            dp[0][i]=0;
        
        int ma = INT_MIN;
        string ans;
        for(auto i=1;i<=a;i++)
            for(auto j=1;j<=b;j++)
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1 + dp[i-1][j-1];
                    if(ma<dp[i][j]){
                        string temp = s.substr(i-dp[i][j],dp[i][j]);
                        string rev = temp;
                        reverse(rev.begin(),rev.end());
                        if(rev==temp){
                            ans=temp;
                            ma=dp[i][j];
                        }
                    }
                }
                else{
                    dp[i][j]= 0;
                }

        return ans;
    }
    string longestPalindrome(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n = s.length();
        int m=n;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        if(n<=2 and s!=s2){
            char ch= s[0];
            string ans ="";
            ans.push_back(ch);
            return ans;
        }
        else if(n<=2 and s==s2)
            return s;
        return lcs(n,m,s,s2,dp);
    }
};