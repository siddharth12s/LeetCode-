class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = INT_MIN;
        int curr_price = INT_MAX;


        for(auto x : prices){
            curr_price = min(curr_price,x);
            ans = max(ans,x-curr_price);
        }

        return ans;
    }
};