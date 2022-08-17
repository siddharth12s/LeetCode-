class Solution {
public:
   string longestPalindrome(string s) {
        int n=s.length();
        string s2=s;
        reverse(s2.begin(),s2.end());
        return LCSS(s,s2,n);
    }
    string LCSS(string s1, string s2, int n)
    {
        string ans;
        int DP[n+1][n+1],max=0;
        for(int i=0; i<=n; ++i)
        {
            for(int j=0; j<=n; ++j)
            {
                if(i==0 || j==0)
                    DP[i][j]=0;
                else if(s1[i-1]==s2[j-1])
                {
                    DP[i][j]=1+DP[i-1][j-1];
                    if(DP[i][j]>max)
                    {
                        string temp=s1.substr(i-DP[i][j],DP[i][j]);
                        string revtemp=temp;
                        reverse(revtemp.begin(),revtemp.end());
                            if(revtemp==temp)
                            {
                                max=DP[i][j];
                                ans=temp;
                            }
                    }
                }
                else
                    DP[i][j]=0;
                
            }
        }
        return ans;
    }
};