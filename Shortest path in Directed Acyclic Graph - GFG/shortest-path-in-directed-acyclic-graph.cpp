//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    void dfs(vector<pair<int,int>> v[], vector<int>& vis, stack<int> &s,int src){
        
        vis[src]=1;
        
        for(auto x: v[src]){
            if(!vis[x.first]){
                dfs(v,vis,s,x.first);
            }
        }
        
        s.push(src);
        return;
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> v[N];
        
        int n = edges.size();
        for(auto i=0;i<n;i++){
            v[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        
        stack<int> s;
        vector<int> vis(N,0);
        
        for(auto i=0;i<N;i++){
            if(!vis[i]){
                dfs(v,vis,s,i);
            }
        }
        
        vector<int> dis(N,1e9);
        dis[0]=0;
        
        while(!s.empty()){
            auto node = s.top();
            s.pop();
            
            // dis[f]=0;
            
            for(auto x : v[node]){
                int Ve = x.first;
                int wt = x.second;
                
                if(dis[Ve]>dis[node]+wt){
                    dis[Ve]= dis[node]+wt;
                }
            }
        }
        
        for(auto i=0;i<N;i++){
            if(dis[i]==1e9)
                dis[i]=-1;
        }
        
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends