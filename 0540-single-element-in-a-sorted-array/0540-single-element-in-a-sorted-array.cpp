class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int l =0, r=n-1;
        
        while(l<=r){
            int m = l + (r-l)/2;
            int s = m-l;
            
            if(m and nums[m]==nums[m-1]){
                if(s%2==0)
                    r=m-2;
                else
                    l=m+1;
            }
            else if(m+1<n and nums[m]==nums[m+1]){
                if(s%2==0)
                    l=m+2;
                else
                    r=m-1;
            }
            
            else return nums[m];
        }
        return -1;
    }
};