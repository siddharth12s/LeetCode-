class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int rightsum = 0;

        for(auto x : nums){
            rightsum += x;
        }

        vector<int> ans;
        int leftsum=0;
        for(auto i=0;i<nums.size();i++){
            rightsum -= nums[i];
            ans.push_back(abs(rightsum-leftsum));
            leftsum += nums[i];
        }
        return ans;
    }
};