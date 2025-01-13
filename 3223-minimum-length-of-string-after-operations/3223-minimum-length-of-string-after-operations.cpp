class Solution {
public:
    int minimumLength(string s) {
        vector<int> v(26,0);

        int ans = s.length();
        for(auto ch : s){
            v[ch-'a']++;
            if(v[ch-'a']==3){
                ans -= 2;
                v[ch-'a']-=2;
            }
            // cout<<v[ch]<<endl;
        }

        return ans;
    }
};