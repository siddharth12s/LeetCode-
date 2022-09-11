class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0;
        int one =0;
        for(auto i=0;i<nums.size();i++){
            if(nums[i]==0)  zero++;
            else if(nums[i]==1) one++;
        }
        
        for(auto i=0;i<zero;i++)
            nums[i]=0;
        for(auto i=zero;i<zero+one;i++)
            nums[i]=1;
        for(auto i=zero+one;i<nums.size();i++)
            nums[i]=2;
        
    }
};