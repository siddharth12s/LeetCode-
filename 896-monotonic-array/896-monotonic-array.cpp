class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool flag1=true;
        for(auto i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                flag1=false;
                break;
            }
        }
        bool flag2=true;
        for(auto i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                flag2=false;
                break;
            }
        }
        return flag1 or flag2;
    }
};