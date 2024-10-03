class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int mini = nums[0];
        for(auto i=1;i<n;i++){
            nums[i]+=nums[i-1];
            mini=min(nums[i],mini);
        }

        return mini<1?1-mini:1;
    }
};