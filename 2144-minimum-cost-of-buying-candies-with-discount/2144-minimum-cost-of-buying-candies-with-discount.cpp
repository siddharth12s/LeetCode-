class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());

        int sum =0;
        int cnt=0;
        for(auto i=0;i<cost.size();){
            if(cnt==2){
                i++;
                cnt=0;
            }else{
                sum+=cost[i];
                i++;
                cnt++;
            }
        }

        return sum;
    }
};