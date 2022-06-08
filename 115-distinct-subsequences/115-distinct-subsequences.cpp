class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<unsigned int> prev(m+1,0);       
        prev[0]=1;
        
        for(auto i=1;i<=n;i++){
            for(auto j=m;j>=1;j--){
                if(s[i-1]==t[j-1])
                    prev[j]=prev[j]+prev[j-1];
            }
        }
        return prev[m];
    }
};