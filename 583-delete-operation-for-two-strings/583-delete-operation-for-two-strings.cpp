class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<int> prev(m+1,0),cur(m+1,0);
        
        for(auto i=1;i<=n;i++){
            for(auto j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1])
                    cur[j]=prev[j-1]+1;
                else
                    cur[j]=max(prev[j],cur[j-1]);
            }
            prev=cur;
        }
        return n-prev[m]+m-prev[m];
    }
};