class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=0,end=nums.size()-1;


        // the single element will break the chain of  pair of index
        // (even,odd)(even,odd)(single element)(odd,even)(odd,even)
        while(start<=end){
            int mid = start + (end-start)/2;
            int index = mid-start;

            if(mid>0 and nums[mid]==nums[mid-1]){
                if(index%2){
                    start=mid+1;
                }else{
                    end=mid-2;
                }
            }else if(mid+1<nums.size() and nums[mid]==nums[mid+1]){
                if(index%2){
                    end=mid-1;
                }else{
                    start=mid+2;
                }
            }else{
                return nums[mid];
            }
        }  
        return -1; 
    }
};