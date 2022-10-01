class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        
        while(l<r){
            int m1=l + (r-l)/3;
            int m2 =  r -(r-l)/3;
            
            if(nums[m1]<nums[m2]){
                l = m1 + 1;
            }else{
                r=m2-1;
            }
        }
        return l;
    }
};