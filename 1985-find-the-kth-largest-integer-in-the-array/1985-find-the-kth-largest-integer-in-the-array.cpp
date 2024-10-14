struct Compare{
    bool operator()(string &a, string &b){
        if(a.size()!=b.size())
            return a.size()<b.size();
        
        return a<b;
    }
};
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, Compare> max_heap;

        for(auto x : nums){
            max_heap.push(x);
        }

        while(!max_heap.empty() and k>1){
            // cout<<max_heap.top()<<endl;
            max_heap.pop();
            k--;
        }

        return max_heap.top();
        
    }
};