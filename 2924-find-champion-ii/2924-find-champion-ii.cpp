class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<int> &vis, int src){

        if(vis[src])
            return;

        vis[src] = 1;

        for(auto nbr : graph[src]){
            if(!vis[nbr]){
                dfs(graph,vis,nbr);
            }
        }

        return;
    }
    int findChampion(int n, vector<vector<int>>& edges) {

        if(n==1)
            return 0;

        if(edges.size()==0)
            return -1;
        
        vector<vector<int>> graph(n);
        for(auto E : edges){
            graph[E[0]].push_back(E[1]);
        }

        vector<int> indegree(n,0);

        for(auto i=0;i<n;i++){
            for(auto nbr : graph[i]){
                indegree[nbr]++;
            }
        }

        int cnt = 0;
        vector<int> ans;
        for(auto i=0;i<n;i++){
            if(indegree[i]==0)   ans.push_back(i);
        }

        return ans.size()>1?-1:ans.back();
    }
};