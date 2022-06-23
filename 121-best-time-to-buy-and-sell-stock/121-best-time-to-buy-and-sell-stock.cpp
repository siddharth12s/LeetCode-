class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxCur=0, maxSf=0;
        for(auto i=1;i<prices.size();i++){
            maxCur= max(0,maxCur += prices[i]-prices[i-1]);
            maxSf = max(maxCur,maxSf);
        }
        return maxSf;
    }
};