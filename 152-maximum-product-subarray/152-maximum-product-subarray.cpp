class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp = 1;
        int minp = 1;
        int ans = -1e9;
        if(nums.size()==1)  return nums[0];
        if(nums.size()==1)  return 0;
        for(auto i=0;i<nums.size();i++){
            if(nums[i]<0)   swap(maxp,minp);
            
            maxp = max(maxp*nums[i],nums[i]);
            minp = min(minp*nums[i],nums[i]);
            ans=max(maxp,ans);
        }
        return ans;
    }
};