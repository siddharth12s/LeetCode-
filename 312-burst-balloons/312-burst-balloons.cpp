class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int m =nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(m+2,vector<int> (m+2,0));
        for(auto i=m;i>=1;i--){
            for(auto j=1;j<=m;j++){
                if(i>j) continue;
                int maxi=INT_MIN;
                for(auto ind=i;ind<=j;ind++){
                int cost = nums[i-1]*nums[ind]*nums[j+1] + dp[i][ind-1] + dp[ind+1][j];
                maxi=max(cost,maxi);
                }
          dp[i][j]=maxi;
        }
    }
        return dp[1][m];
    }
};