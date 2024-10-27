class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        string temp = s;
        vector<int> m(26,0);
        
        for(auto ch : s){
            m[ch-'a']++;
        }
        int mod = 1e9+7;
        
        while(t>0){
            vector<int> m2(26,0);
            for(auto i=0;i<25;i++){
                m2[i+1] = m[i];
            }
            
            m2[0]=m[25];
            m2[1]=(m2[1]+m[25])%mod;

            m=m2;
            t--;
        }
        
        int ans = 0;
        for(auto x : m){
            ans = (ans+x)%mod;
        }
    
        return ans;
    }
};