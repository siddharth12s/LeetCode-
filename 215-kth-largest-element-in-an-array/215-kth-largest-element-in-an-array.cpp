class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for(auto x: nums)
            pq.push(x);
        
        int ans;
        while(k>0){
            ans = pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }
};