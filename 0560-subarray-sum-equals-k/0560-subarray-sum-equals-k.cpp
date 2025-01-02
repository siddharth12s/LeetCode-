class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int start=0,end=0;

        int sum=0;
        int ans = 0;

        if(nums.size()==1){
            return k==nums[0];
        }
        while(end<nums.size()){
            sum += nums[end];

            while(sum>k){
                sum-=nums[start];
                start++;
            }
            if(sum==k){
                ans++;
            }

            end++;
        }

        return ans;
    }
};