class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j=0,i=0,n=s.length();
        unordered_set<char> a;
        
        int ans=0;
        while(i<n and j<n){
            if(a.find(s[j])==a.end()){
                a.insert(s[j]);
                j++;
                ans=max(ans,j-i);
            }
            else{
                a.erase(s[i]);
                i++;
            }
        }
         return ans;       
    }
};