class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(auto i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }

        while(k--){
            int mini = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            nums[idx] = mini*multiplier;
            pq.push({mini*multiplier,idx});
        }

        return nums;
    }
};