class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        vector<int> val(amount+1);
        val[0]=0;
        for(auto i=1;i<=amount;i++){
            val[i]=INT_MAX;
            for(auto c : coins){
                if(i-c<0)   break;
                
                if(val[i-c]!=INT_MAX)  val[i]=min(val[i],val[i-c]+1);
            }
        }
            return val[amount]==INT_MAX? -1: val[amount];
    }
};