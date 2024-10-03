class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        
        int n = nums.size();
        int leftsum=0,rightsum=0;
        
        for(auto i=0;i<n;i++){
            rightsum+=nums[i];
        }

        for(auto i=0;i<n;i++){
            rightsum -=nums[i];

            if(rightsum==leftsum)
                return i;
            leftsum += nums[i];
        }

        return -1;
    }
};