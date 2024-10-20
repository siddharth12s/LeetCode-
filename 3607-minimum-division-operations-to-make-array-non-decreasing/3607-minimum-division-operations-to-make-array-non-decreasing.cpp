class Solution {
public:
    int proper_divisor(int n, int elem){
        for(int i=sqrt(n);i>=1;i--){
            if(n%i==0 and i<=elem){
                return i;
            }
        }
        return 1;
    }
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=n-2;i>=0;i--){
            while(nums[i]>nums[i+1]){
                int div = proper_divisor(nums[i],nums[i+1]);

                if(div==1 and nums[i]>nums[i+1])   return -1;
                nums[i]=div;
                ans++;
            }
        }
        return ans;
    }
};