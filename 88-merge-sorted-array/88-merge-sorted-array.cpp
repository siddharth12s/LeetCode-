class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(m+n);
        
        int i=0,j=0,k=0;
        
        while(i<m and j<n){
            
            if(nums1[i]<nums2[j])
                ans[k++]=nums1[i++];
            else
                ans[k++]=nums2[j++];
        }
        
        for(;i<m;i++){
            ans[k++]=nums1[i];
        }
        for(;j<n;j++){
            ans[k++]=nums2[j];
        }
        nums1=ans;
    }
};