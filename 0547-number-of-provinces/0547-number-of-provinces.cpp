class Solution {
public:

    void dfs(vector<vector<int>> &graph, vector<int> &vis, int src){
        vis[src]=1;

        for(auto nbr: graph[src]){
            if(!vis[nbr]){
                dfs(graph,vis,nbr);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> graph(n+1);

        for(auto i=0;i<n;i++){
            for(auto j=0;j<n;j++){
                if(i==j)    continue;
                if(isConnected[i][j]){
                    graph[i+1].push_back(j+1);
                }
            }
        }

        int cnt = 0;
        vector<int> vis(n+1,0);
        // dfs(graph,vis,1,cnt);
        for(auto i=1;i<=n;i++){
            if(!vis[i]){
                cnt++;
                dfs(graph,vis,i);
            }
        }

        return cnt;
    }
};