class Solution {
public:
    int f(vector<int>& nums,int s,int e,int k){
        if(e>=s){
            int mid = (s+e)/2;
            if(nums[mid]==k)
                return mid;
            
            if(nums[mid]>k){
                return f(nums,s,mid-1,k);
            }
                return f(nums,mid+1,e,k);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int start=0;
        int end = nums.size()-1;
        int ans = f(nums,start,end,target);
        
        return ans;
    }
};