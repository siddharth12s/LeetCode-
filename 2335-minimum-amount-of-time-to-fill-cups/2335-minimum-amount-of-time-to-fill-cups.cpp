class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> max_heap;

        for(auto x : amount){
            max_heap.push(x);
        }

        int ans = 0;
        while(max_heap.top()!=0){
            int first = max_heap.top();
            max_heap.pop();

            int second = max_heap.top();
            max_heap.pop();

            max_heap.push(first-1);
            max_heap.push(second-1);
            ans++;
        }

        return ans;
    }
};