class Solution {
public:
    int maxScore(string s) {
        
        int ans = INT_MIN;

        for(auto i=1;i<s.size();i++){
            auto left = s.substr(0,i);
            auto right = s.substr(i,(s.size()-i));

            int zero = 0;
            for(auto &ch : left){
                if (ch=='0')
                    zero++;
            }

            int one = 0;
            for(auto &ch : right){
                if(ch=='1')
                    one++;
            }

            ans=max(ans,one+zero);
        }

        return ans;
    }
};