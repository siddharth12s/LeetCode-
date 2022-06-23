class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        map<int,int> ma;
        vector<int> ans;
        for(auto i=0;i<n;i++)
            ma[nums1[i]]++;
        
        for(auto i=0;i<m;i++){
            if(ma[nums2[i]]>0){
                ma[nums2[i]]--;
                ans.push_back(nums2[i]);
            }
        }
       return ans; 
    }
};