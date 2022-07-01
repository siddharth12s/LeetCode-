class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        map<int,int> m;
        for(auto i=0;i<n;i++){
            for(auto j=0;j<2;j++){
                m[edges[i][j]]++;
            }
        }
        int ans;
        for(auto& it: m){
            if(it.second==n)
                ans= it.first;
        }
        return ans;
    }
};