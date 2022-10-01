class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        
        int low =0;
        int high=nums.size()-1;
        
        //First Occurence
        int f=-1,l=-1;
        while(low<=high){
            int m = low + (high-low)/2;
            
            if(nums[m]==target){
                f=m;
                high=m-1;
            }else if(nums[m]>target){
                high=m-1;
            }
            else{
                low = m+1;
            }
        }
        
        //Last Occurence
         low =0;
         high=nums.size()-1;
        
        while(low<=high){
            int m = low + (high-low)/2;
            
            if(nums[m]==target){
                l=m;
                low=m+1;
            }else if(nums[m]>target){
                high=m-1;
            }
            else{
                low = m+1;
            }
        }
        
        ans.push_back(f);
                ans.push_back(l);
        
        return ans;

        
    }
};