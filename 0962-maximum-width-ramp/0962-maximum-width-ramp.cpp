class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        vector<int> rightMax(n,0);
        rightMax[n-1] = nums[n-1];

        for(int i=n-2;i>=0;i--){
            rightMax[i] = max(rightMax[i+1],nums[i]);
        }

        int start =0, end = 0;
        while(end<n){
            while(start<end and nums[start]>rightMax[end]){
                start++;
            }
            ans = max(end-start,ans);
            end++;
        }
        return ans;
    }
};