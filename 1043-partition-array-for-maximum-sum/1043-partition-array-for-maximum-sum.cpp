class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        for(auto i=n-1;i>=0;i--){
            
            int maxi=INT_MIN;
            int maxans=INT_MIN,len=0;
            int sum=0;
            for(auto j=i;j<min(n,i+k);j++){
                len++;
                maxi=max(maxi,arr[j]);
                sum=(len*maxi) + dp[j+1];
                maxans=max(maxans,sum);
            }
            dp[i]=maxans;
        }
        return dp[0];
    }
};