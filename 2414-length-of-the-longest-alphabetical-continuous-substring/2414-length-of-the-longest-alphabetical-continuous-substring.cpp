class Solution {
public:
    int longestContinuousSubstring(string s) {
        
        int ans=0;
        
        int n = s.length();
        int len=1;
        for(auto i=1;i<n;i++){
            if(s[i-1]+1==s[i]){
                len++;
            }
            else{
                ans=max(len,ans);
                len=1;
            }
        }
        return max(ans,len);
    }
};