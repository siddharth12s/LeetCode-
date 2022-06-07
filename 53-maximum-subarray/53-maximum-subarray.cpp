class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=nums[0];
        int cursum=nums[0];
        for(auto i=1;i<nums.size();i++){
            cursum = max(cursum + nums[i],nums[i]);
            maxsum=max(cursum,maxsum);
        }
        return maxsum;
    }
};