class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;

        // int i=0,j=i+1;
        int n = words.size();
        
        for(auto i=0;i<n;i++){
            for(auto j=i+1;j<n;j++){
                string s1 = words[i];
                string s2 = words[j];

                if(s1.size()>s2.size()) continue;

                if(s2.find(s1)==0 and s2.rfind(s1) == s2.size()-s1.size()){
                    ans++;
                }
            }
        }

        return ans;
    }
};