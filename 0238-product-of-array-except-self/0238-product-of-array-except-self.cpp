class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // vector<int> suffix(n,1),prefix(n,1);

        vector<int> ans(n,1);
        int curr=1;
        for(auto i=0;i<n;i++){
            ans[i]*=curr;
            curr*=nums[i];
        }

        curr=1;
        for(auto i=n-1;i>=0;i--){
            ans[i]*=curr;
            curr*=nums[i];
        }


        return ans;

    }
};