class Solution {
public:
    
    void dfs(vector<int> graph[],vector<int> & vis,int i){
        
        vis[i]=1;
        
        for(auto x : graph[i]){
            if(!vis[x])
                dfs(graph,vis,x);
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
       
        int n = isConnected.size();
        vector<int> graph[n];
        
        for(auto i=0;i<n;i++){
            for(auto j=0;j<n;j++){
                if(isConnected[i][j])
                    graph[i].push_back(j);
            }
        }
        
        int ans=0;
        vector<int> vis(n,0);
        for(auto i=0;i<n;i++){
            if(!vis[i])
                ans++;
                dfs(graph,vis,i);
        }
        
        return ans;
    }
};