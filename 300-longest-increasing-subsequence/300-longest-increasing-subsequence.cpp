class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for(auto i=0;i<nums.size();i++){
            if(ans.empty() or ans.back()<nums[i]){
                ans.push_back(nums[i]);
            }
            else{
                auto it = lower_bound(ans.begin(),ans.end(),nums[i]);
                *it=nums[i];
            }
        }
        return ans.size();
    }
};