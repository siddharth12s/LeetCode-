class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        
        vector<int> prev(m+1,0),cur(m+1,0);
        
       // for(auto i=0;i<=n;i++) dp[i][0]=i;
        for(auto i=0;i<=m;i++) prev[i]=i;
        
        for(auto i=1;i<=n;i++){
            cur[0]=i;
            for(auto j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1])
                    cur[j]= prev[j-1];
                else
                    cur[j]= 1 + min(prev[j],min(cur[j-1],prev[j-1]));
            }
            prev = cur;
        }
        return prev[m];
    }
};