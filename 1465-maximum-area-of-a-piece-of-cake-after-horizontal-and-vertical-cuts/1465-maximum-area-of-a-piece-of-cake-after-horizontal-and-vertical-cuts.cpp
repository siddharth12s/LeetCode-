class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int n=horizontalCuts.size();
        int m=verticalCuts.size();
        auto maxh=max(horizontalCuts[0],h-horizontalCuts[n-1]);
        auto maxw=max(verticalCuts[0],w-verticalCuts[m-1]);
        for(auto i=1;i<n;i++){
            maxh=max(maxh,horizontalCuts[i]-horizontalCuts[i-1]);
        }
        for(auto i=1;i<m;i++){
            maxw=max(maxw,verticalCuts[i]-verticalCuts[i-1]);
        }
        
        int mod = 1e9 + 7;
        return (long)maxh * maxw % 1000000007;
    }
};