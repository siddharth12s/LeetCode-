class Solution {
public:
 int getFirstGreaterOrEqual(vector<int>& nums, int val) {
        int start = 0;
        int end = nums.size() - 1;

        int index = nums.size();
        while (start <= end) {
            int mid = (start + end) / 2;

            if (nums[mid] >= val) {
                index = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return index;
    }
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        int start = 0,end = n-1;
        sort(nums.begin(),nums.end());
        
        for(auto i=1;i<=n;i++){
            int k = getFirstGreaterOrEqual(nums, i);
            
            if (n - k == i) {
                return i;
            }
        }

        return -1;
    }
};