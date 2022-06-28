class Solution {
public:
    int minDeletions(string s) {
        
        int n = s.length();
        vector<int> m(26,0);
        for(auto i=0;i<n;i++){
            m[s[i]-'a']++;
        }
        int ans=0;
        sort(m.begin(),m.end(),greater<int> ());
        for(auto i=1;i<26;i++){
            if(m[i]==0) break;
            if(m[i]>=m[i-1]){
                int prev=m[i];
                m[i]=max(0,m[i-1]-1);
                ans += prev-m[i];
            }
        }
        return ans;
    }
};