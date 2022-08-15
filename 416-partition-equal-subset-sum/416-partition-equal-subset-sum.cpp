class Solution {
public:
//     bool f(vector<int> &nums,vector<vector<int>> &dp,int ind,int target){
//         if(target==0)   return 1;
//         if(ind==0)  return nums[0]==target;
        
//         if(dp[ind][target]!=-1) return dp[ind][target];
        
//         bool nottake = f(nums,dp,ind-1,target);
//         bool take = false;
//         if(target>=nums[ind]){
//             take = f(nums,dp,ind-1,target-nums[ind]);
//         }
        
//         return dp[ind][target]=take or nottake;
        
//     }
    bool canPartition(vector<int>& nums) {
        int totsum =0;
        for(auto i=0;i<nums.size();i++)
            totsum += nums[i];
        
        if(totsum%2)    return false;

        vector<vector<bool>> dp(nums.size(),vector<bool>((totsum/2)+1,false));
        if(totsum/2>=nums[0])   dp[0][nums[0]]=true;
        for(auto i=0;i<nums.size();i++) dp[i][0]=true;
            
        for(auto i=1;i<nums.size();i++){
            for(auto j=1;j<=totsum/2;j++){
                bool nottake = dp[i-1][j];
                bool take = false;
                if(j>=nums[i])  take = dp[i-1][j-nums[i]];
                    
                dp[i][j]=take | nottake;
            }
        }
        return dp[nums.size()-1][totsum/2];
    }
};