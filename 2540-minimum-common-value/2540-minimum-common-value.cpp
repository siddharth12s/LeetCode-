class Solution {
public:
    int binary_search(vector<int> &v, int target){
        int start = 0, end = v.size()-1;
        while(start<end){
            int mid = start + (end-start)/2;
            if(v[mid]==target){
                return v[mid];
            }else if (v[mid]>target){
                end = mid;
            }else{
                start = mid+1;
            }
        }
        return -1;
    }

    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int ans = -1;
        
        if(nums2.size()>nums1.size()){
            return getCommon(nums2,nums1);
        }

        for(auto x : nums2){
            ans = binary_search(nums1,x);
            if(ans!=-1)
                break;
        }

        return ans;
    }
};