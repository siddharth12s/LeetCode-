class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        
        while(l<r){
            int m1=l + (r-l)/2;
            if(nums[m1]<nums[m1+1]){
                l = m1 + 1;
            }else{
                r=m1;
            }
        }
        return l;
    }
};