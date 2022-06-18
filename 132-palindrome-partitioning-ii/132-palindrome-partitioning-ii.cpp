class Solution {
public:
    bool isPalin(int i,int j, string &s){
        while(i<j){
            if(s[i]!=s[j])  return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string &s) {
        int n = s.length();
        vector<int> dp(n+1,0);
        
        for(auto i=n-1;i>=0;i--){
            int minc= INT_MAX;
            for(auto j=i;j<n;j++){
                if(isPalin(i,j,s)){
                    int cost = 1+ dp[j+1];
                    minc=min(cost,minc);
                }
            }
            dp[i]=minc;
        }
        return dp[0]-1;
    }
};