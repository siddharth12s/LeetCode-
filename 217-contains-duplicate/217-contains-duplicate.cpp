class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        bool flag=false;
        for(auto i=0;i<n-1;i++){
            
            if((nums[i]^nums[i+1])==0){
                flag=true;
                break;
            }
        }
        return flag;
    }
};