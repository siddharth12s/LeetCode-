class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topsum = 0;
        for(auto i=0;i<grid[0].size();i++){
            topsum += grid[0][i];
        }

        long long bottomsum=0;
        long long ans = LLONG_MAX;
        for(auto i=0;i<grid[0].size();i++){
            topsum -= grid[0][i];
            ans = min(ans,max(topsum,bottomsum));
            bottomsum += grid[1][i];
        }

        return ans;

    }
};