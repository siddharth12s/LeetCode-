class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> pq;

        for(auto &x : gifts){
            pq.push((long long)x);
        }

        while(k--){
            long long elem = pq.top();
            pq.pop();

            long long num = (long long)sqrt(elem);
            pq.push(num);
        }

        long long ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};