class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        gain.push_back(0);
        int maxi = gain[0];
        for(auto i=1;i<gain.size();i++){
            gain[i]+=gain[i-1];
            maxi = max(maxi,gain[i]);
        }

        return maxi<0?0:maxi;
    }
};