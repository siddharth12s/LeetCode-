class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> q(k);
        vector<int> ans;
        for(int i=0;i<k;i++){
            
            while(!q.empty() and nums[i]>nums[q.back()])
                q.pop_back();
            
            q.push_back(i);
        }
        
        for(auto i=k;i<n;i++){
            ans.push_back(nums[q.front()]);
            
            while(!q.empty() and q.front()<=i-k)
                q.pop_front();
            
            while(!q.empty() and nums[i]>=nums[q.back()])
                q.pop_back();
            
            q.push_back(i);  
        }
        ans.push_back(nums[q.front()]);
        
        return ans;
    }
};