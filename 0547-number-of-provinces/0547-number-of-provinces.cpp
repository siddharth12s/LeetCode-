class Solution {
public:
    
    void dfs(vector<int> adj[], vector<int> &vis, int src){
        
        vis[src]=1;
        
        for(auto x : adj[src]){
            if(!vis[x]){
                dfs(adj,vis,x);
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int> adj[n];
        
        for(auto i=0;i<n;i++){
            for(auto j=0;j<n;j++){
                if(i==j)
                    continue;
                
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n,0);
        int ans=0;
        for(auto i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                ans++;
            }
        }
        
        return ans;
    }
};