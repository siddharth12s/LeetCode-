class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int minP = prices[0];
        int maxP=0;
        for(auto x: prices){
            if(x<minP)  minP=x;
            else    maxP=max(maxP,x-minP);
        }
        return maxP;
    }
};