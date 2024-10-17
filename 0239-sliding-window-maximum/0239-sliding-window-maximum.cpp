class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        int start=0,end=0;
        int maxi = nums[0];
        deque<int> dq;
        while(end<nums.size()){
            
            if(!dq.empty() and dq.front()==end-k)   dq.pop_front();
            while(!dq.empty() and nums[dq.back()]<nums[end]){
                dq.pop_back();
            }

            dq.push_back(end);
            if(end>=k-1)    ans.push_back(nums[dq.front()]);
            end++;
        }

        return ans;
    }
};