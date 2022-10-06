class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        int count=0;
        int i,j;
        for(auto k=n-1;k>1;k--){
            for(i=0,j=k-1;i<j;){
                if(nums[i]+nums[j]>nums[k]){
                    count+=j-i;
                    j--;
                }else{
                    i++;
                }
            }
        }
        return count;
    }
};