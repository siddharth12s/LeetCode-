class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int> , greater<int>> min_heap;

        for(auto x : matrix){
            for(auto y : x){
                min_heap.push(y);
            }
        }

        while(k>1){
            min_heap.pop();
            k--;
        }

        return min_heap.top();
    }
};