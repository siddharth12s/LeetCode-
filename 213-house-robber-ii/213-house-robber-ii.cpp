class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    return nums[0];
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        dp1[0]=nums[0];
        for(auto i=1;i<n-1;i++){
            int take = nums[i];
            if(i-2>=0)  take += dp1[i-2];
            int nottake= dp1[i-1];
            dp1[i]=max(take,nottake);
        }
        dp2[0]=0;
        dp2[1]=nums[1];
        for(auto i=2;i<n;i++){
            int take = nums[i];
            if(i-2>=0)  take += dp2[i-2];
            int nottake= dp2[i-1];
            dp2[i]=max(take,nottake);
        }
        cout<<dp1[n-2]<<" "<<dp2[n-1];
        return max(dp1[n-2],dp2[n-1]);
    }
};