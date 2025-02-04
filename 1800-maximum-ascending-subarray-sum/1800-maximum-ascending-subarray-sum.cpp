class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int prev=nums[0];
        int max_sum = prev;
        int curr_sum = prev;

        for(auto i=1;i<nums.size();i++){
            if(nums[i]<=prev){
                curr_sum=nums[i];
                prev=nums[i];
                cout<<curr_sum<<endl;
                continue;
            }
            prev=nums[i];
            curr_sum += nums[i];
            max_sum = max(max_sum,curr_sum);
        }

        return max_sum;
    }
};