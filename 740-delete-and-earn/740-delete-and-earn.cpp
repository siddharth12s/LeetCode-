class Solution {
public:

    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> freq(nums[n-1]+1,0);
        for(auto i=0;i<n;i++)   freq[nums[i]]++;
        vector<int> dp(nums[n-1]+1);
        dp[0]=0;
        for(auto i=1;i<nums[n-1]+1;i++){
            int take = i*freq[i];
            if(i-2>=0)  take+=dp[i-2];
            int nottake = dp[i-1];
            dp[i]=max(take,nottake);
        }
        return dp[nums[n-1]];;
    }
};