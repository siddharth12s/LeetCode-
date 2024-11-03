class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        priority_queue<int> max_heap;
        for(auto i=0;i<numOnes;i++){
            max_heap.push(1);
        }
        for(auto i=0;i<numZeros;i++){
            max_heap.push(0);
        }
        for(auto i=0;i<numNegOnes;i++){
            max_heap.push(-1);
        }

        int ans = 0;
        while(k--){
            ans += max_heap.top();
            max_heap.pop();
        }

        return ans;
    }
};