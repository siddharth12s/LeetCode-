class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        
        int maxP =0;
        int res=INT_MIN;
        for(auto i=0;i<n;i++){
            res = max(res,maxP+values[i]-i);
            maxP = max(maxP,values[i]+i);
            
        }
        return res;
    }
};