class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        
        for(auto j=0;j<n;j++){
            if(nums[j]%2==0){
                swap(nums[i],nums[j]);
                i++;
            }
        }
        return nums;
    }
};