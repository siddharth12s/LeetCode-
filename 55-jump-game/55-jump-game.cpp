class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[n-1]=1;
        for(auto i=n-2;i>=0;i--){
            if(nums[i]==0){
                dp[i]=0;
                continue;
            }
            
            
            int dest = i + nums[i];
            int flag=0;
            for(auto jumps = i+1; jumps<= dest; jumps++){
                if(jumps<nums.size() and dp[jumps]){
                    dp[i]=1;
                    flag=1;
                    break;
                }
                if(flag==1) continue;
                dp[i]=0;
            }
        }
        return dp[0];
        
    }
};