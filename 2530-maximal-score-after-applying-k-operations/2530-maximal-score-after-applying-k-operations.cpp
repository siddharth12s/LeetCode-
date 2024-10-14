class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<long long> pq;
        for(auto x : nums){
            pq.push((long long)x);
        }
        while(k>0){
            auto elem = pq.top();
            ans += elem;
            pq.pop();
            if(elem%3){
                pq.push(elem/3 + 1);
            }else{
                pq.push(elem/3);
            }
            k--;
        }
        return ans;
    }
};