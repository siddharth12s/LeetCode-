class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        int i=0,j=0;
        int s=0;
        int res=INT_MAX;
        while(j<n){
            s+=nums[j++];
            while(s>=target){
                res=min(res,j-i);
                s-=nums[i++];
            }
        }
        return res==INT_MAX?0:res;
    }
};