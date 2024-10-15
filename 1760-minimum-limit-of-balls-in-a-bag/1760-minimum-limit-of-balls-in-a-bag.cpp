class Solution {
public:
    bool feasible(vector<int> &v,int k, int mid){
        int cnt = 0;
        for(auto x : v){
            cnt += (x-1)/mid;
            if (cnt>k)
                return true;
        }

        return false;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int start=1,end = *max_element(nums.begin(),nums.end());
        // int ans = 0;
        while(start<=end){
            int mid = start + (end-start)/2;
            if (feasible(nums,maxOperations,mid)){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }

        return start;
    }
};