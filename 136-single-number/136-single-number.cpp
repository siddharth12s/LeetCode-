class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for(auto i=1;i<nums.size();i++)
            ans = (ans^nums[i]);
        
        return ans;
    }
};