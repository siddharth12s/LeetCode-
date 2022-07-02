class Solution {
public:
    void dfs(vector<int> &path,vector<vector<int>> &ans,int s,int e,vector<vector<int>>& graph){
        if(s==e){
            ans.push_back(path);
            return;
        }
        for(auto x : graph[s]){
            path.push_back(x);
            dfs(path,ans,x,e,graph);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> path;
        path.push_back(0);
        dfs(path,ans,0,n-1,graph);
        return ans;
    }
};