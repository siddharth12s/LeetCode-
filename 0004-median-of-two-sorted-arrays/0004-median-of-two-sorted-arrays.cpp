class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int i=0,j=0;

        while(i<nums1.size() and j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            }else{
                arr.push_back(nums2[j]);
                j++;
            }
        }

        if(i==nums1.size() and j<nums2.size()){
            for(auto k=j;k<nums2.size();k++){
                arr.push_back(nums2[k]);
            }
        }
        if(i<nums1.size() and j==nums2.size()){
            for(auto k=i;k<nums1.size();k++){
                arr.push_back(nums1[k]);
            }
        }

        double ans = 0;
        int start=0,end=arr.size()-1;
        if((end-start+1)%2){
            ans =(double) arr[start + (end-start)/2];
        }else{
            int mid1 = (start + (end-start)/2);
            int mid2 = mid1+1;
            ans  = ((double)arr[mid1] + (double)arr[mid2])/2.0;
        }
        return ans;
    }
};