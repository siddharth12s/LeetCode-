class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> min_heap;

        for(auto x :  nums){
            min_heap.push(x);
        }

        while(k>0){
            int elem = min_heap.top();
            min_heap.pop();

            min_heap.push(-1*elem);
            k--;
        }

        int ans=0;
        while(min_heap.size()>0){
            ans+=min_heap.top();
            min_heap.pop();
        }

        return ans;
    }
};