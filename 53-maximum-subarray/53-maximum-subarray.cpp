class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxs=nums[0];
        int curs=nums[0];
        
        for(auto i=1;i<nums.size();i++){
            curs = max(curs+nums[i],nums[i]);
            maxs = max(maxs,curs);
        }
        return maxs;
    }
};