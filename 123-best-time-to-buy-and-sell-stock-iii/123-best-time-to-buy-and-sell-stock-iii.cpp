class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> cur(5,0),ahead(5,0);
        
        for(auto i=0;i<5;i++)
            ahead[i]=0;
        for(auto i=0;i<=n;i++)
            cur[4]=0;
        
        for(auto i=n-1;i>=0;i--){
            for(auto j=3;j>=0;j--){
                if(j%2==0)
                    cur[j]=max(-prices[i]+ahead[j+1],ahead[j]);
                else
                    cur[j]=max(prices[i]+ahead[j+1],ahead[j]);
            }
            ahead = cur;
        }
        return ahead[0];
    }
};