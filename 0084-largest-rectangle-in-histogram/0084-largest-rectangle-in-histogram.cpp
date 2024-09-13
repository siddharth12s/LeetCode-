class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        heights.push_back(0);
        stack<int> index;
        index.push(0);
        for(auto i=0;i<heights.size();i++){

            while(!index.empty() and heights[index.top()]>heights[i]){
                int h = heights[index.top()];
                index.pop();

                int l = index.empty()?-1:index.top();

                ans = max(ans,(i-l-1)*h);
            }
            index.push(i);
        }

        return ans;
    }
};