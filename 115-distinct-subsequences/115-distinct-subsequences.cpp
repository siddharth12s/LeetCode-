class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<unsigned int> prev(m+1,0),cur(m+1,0);
        for(auto i=0;i<=n;i++) cur[0]=1;        
        prev[0]=1;
        
        for(auto i=1;i<=n;i++){
            for(auto j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                    cur[j]=prev[j]+prev[j-1];
                else
                    cur[j]=prev[j];
            }
            prev = cur;
        }
        return prev[m];
    }
};