class Solution {
public:
    int maxScore(string s) {
        
        int ans = INT_MIN;

        int n = s.size();

        for(auto i=1;i<n;i++){
            string s1 = s.substr(0,i);
            string s2 = s.substr(i,(n-i));

            int cnt_zero=0,cnt_one=0;

            for(auto &ch : s1){
                if(ch=='0')
                    cnt_zero++;
            }

            for(auto &ch : s2){
                if(ch=='1')
                    cnt_one++;
            }

            ans = max(ans,cnt_zero+cnt_one);

        }

        return ans;
    }
};