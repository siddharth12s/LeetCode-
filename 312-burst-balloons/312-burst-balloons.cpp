class Solution {
public:
    int f(int i,int j,vector<int> &nums,vector<vector<int>> &dp){
       
        if(i>j) return 0;
        int maxi=INT_MIN;
        if(dp[i][j]!=-1) return dp[i][j];
        for(auto ind=i;ind<=j;ind++){
            int cost = nums[i-1]*nums[ind]*nums[j+1] + f(i,ind-1,nums,dp) + f(ind+1,j,nums,dp);
            maxi=max(cost,maxi);
        }
        return dp[i][j]=maxi;    
    }
    
    int maxCoins(vector<int>& nums) {
        int m =nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(m+2,vector<int> (m+2,-1));
        return f(1,m,nums,dp);
    }
};