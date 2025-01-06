class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int ans = 0;

        for(auto i=1;i<nums.size();i++){
            nums[i] += nums[i-1];
        }

        for(auto x : nums){
            if(x==0)    ans++;
        }

        return ans;
    }
};