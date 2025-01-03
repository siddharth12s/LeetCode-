class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long rightsum = 0, leftsum=0;

        for(auto i=0;i<n;i++){
            rightsum += nums[i];
        }
        leftsum = 0;

        int cnt = 0;
        for(auto i=0;i<n-1;i++){
            rightsum -= nums[i];
            leftsum += nums[i];

            if(leftsum>=rightsum)
                cnt++;
        }

        return cnt;
    }
};