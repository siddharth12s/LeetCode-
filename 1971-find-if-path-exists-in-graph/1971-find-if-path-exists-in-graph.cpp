class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>& vis,int s,int e){
        if(s==e)
            return true;
        // if(vis[s])
        //     return false;
        
        vis[s]=1;
        for(auto x : graph[s]){
            if(!vis[x]){
                vis[x]=1;
                if(dfs(graph,vis,x,e))
                    return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> graph(n);
        for(auto el : edges){
            graph[el[0]].push_back(el[1]);
            graph[el[1]].push_back(el[0]);
        }
        
        vector<int> vis(n,0);
        return dfs(graph,vis,source,destination);
    }
};