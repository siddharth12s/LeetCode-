class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans = 0;
        set<int> st;

        for(auto &x : banned){
            st.insert(x);
        }

        int sum = 0;
        for(auto i=1;i<=n;i++){
            if(st.count(i)==0 and (sum+i)<=maxSum){
                sum+=i;
                ans++;
            }
        }

        return ans;
    }
};