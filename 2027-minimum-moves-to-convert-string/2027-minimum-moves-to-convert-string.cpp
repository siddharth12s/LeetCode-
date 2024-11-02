class Solution {
public:
    int minimumMoves(string s) {
        // sort(s.begin(),s.end());
        int ans = 0;
        for(auto i=0;i<s.length();){
            if(s[i]=='O'){
                i++;
                continue;
            }    
            else{
                ans++;
                i+=3;
            } 
        }
        return ans;
    }
};