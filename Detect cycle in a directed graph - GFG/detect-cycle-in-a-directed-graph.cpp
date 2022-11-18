//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[],int vis[],int pathVis[],int i){
        
        vis[i]=1;
        pathVis[i]=1;
        
        for(auto it : adj[i]){
            if(!vis[it]){
                if(dfs(adj,vis,pathVis,it))
                    return true;
            }
            else if(pathVis[it]){
                return true;
            }
        }
        pathVis[i]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pathVis[V]={0};
        
        for(auto i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj,vis,pathVis,i))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends