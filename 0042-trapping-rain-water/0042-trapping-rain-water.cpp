class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;

        vector<int> mxl(height.size(),0),mxr(height.size(),0);

        mxl[0] = height[0];
        mxr[height.size()-1] = height[height.size()-1];

        for(auto i=1;i<height.size();i++){
            mxl[i]=max(mxl[i-1],height[i]);
        }
        for(int i=height.size()-2;i>=0;i--){
            mxr[i]=max(mxr[i+1],height[i]);
        }

        vector<int> water;
        for(auto i=0;i<height.size();i++){
            water.push_back(min(mxl[i],mxr[i])-height[i]);
        }

        for(auto x : water){
            ans += x;
        }

        return ans;
    }
};