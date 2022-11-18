class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color(n,-1);
        
        queue<pair<int,int>> q;
        // q.push({0,0});
        
        // int prev=0;
        for(auto i=0;i<n;i++){
            if(color[i]==-1){
                q.push({i,0});
            } 
                while(!q.empty()){
                    int node = q.front().first;
                    int col = q.front().second;
                    q.pop();


                    for(auto x : graph[node]){
                        if(color[x]==-1){
                            color[x]=(col^1);
                            q.push({x,(col^1)});
                        }
                        else if(color[x]==color[node])
                            return false;
                    }
                }
        }
        return true;
    }
};