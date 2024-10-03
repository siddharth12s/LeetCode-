class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n,1),prefix(n,1);

        for(auto i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }

        for(auto i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i+1];
        }

        vector<int> ans(n,1);
        for(auto i=0;i<n;i++){
            ans[i]=suffix[i]*prefix[i];
        }
        return ans;

    }
};