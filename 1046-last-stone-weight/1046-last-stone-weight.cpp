class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(auto x : stones){
            pq.push(x);
        }

        while(pq.size()>1){
            int heaviest = pq.top();
            pq.pop();
            int second_heaviest = pq.top();
            pq.pop();

            if(second_heaviest<heaviest){
                pq.push(heaviest-second_heaviest);
            }
        }

        return pq.empty()?0:pq.top();
    }
};