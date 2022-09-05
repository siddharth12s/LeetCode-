class Solution {
public:
    int f(string &s, int i,int k, char dum,vector<vector<int>> &dp){
        if(i==s.length())
            return 0;
        
        if(dp[i][dum]!=-1) return dp[i][dum];
        
        int pick=0;
        if(abs(int(s[i])-int(dum))<=k or dum=='#')
            pick = 1+f(s,i+1,k,s[i],dp);
        int notpick = f(s,i+1,k,dum,dp);
        return dp[i][dum]=max(pick,notpick);
    }
    int longestIdealString(string s, int k) {
        vector<vector<int>> dp(s.length()+1,vector<int>(150,-1));
        return f(s,0,k,'#',dp);
    }
};