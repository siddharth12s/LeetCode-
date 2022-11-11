class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i = 0;
        int n = nums.size();
        int j=1;
        while(j<n){
            if(nums[j]==nums[i]){
                j++;
                continue;
            }else{
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};