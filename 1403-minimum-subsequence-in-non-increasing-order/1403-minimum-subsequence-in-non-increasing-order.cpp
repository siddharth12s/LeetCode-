class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int sum  = 0;

        for(auto x : nums){
            sum += x;
        }

        int check_sum=0;
        vector<int> ans;
        while(check_sum<=sum){
            ans.push_back(nums.back());
            check_sum += ans.back();
            sum -= nums.back();
            nums.pop_back();
        }

        return ans;
    }
};