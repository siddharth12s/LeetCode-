class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;

        vector<int> max_at_left(height.size(),0), max_at_right(height.size(),0);

        int l =-1,r=-1;
        int n= height.size();
        for(auto i=0;i<n;i++){
            max_at_left[i] = max(l,height[i]);
            l=max(l,height[i]);
        }

        for(auto i=n-1;i>=0;i--){
            max_at_right[i]=max(r,height[i]);
            r = max(r,height[i]);
        }

        for(auto i=0;i<n;i++){
            ans += min(max_at_left[i],max_at_right[i]) - height[i];
        }

        return ans;
    }
};