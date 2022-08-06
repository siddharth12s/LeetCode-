class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        unordered_map<int,vector<pair<int,int>>> m;
        
        for(auto i=0;i<edges.size();i++){
            m[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
            m[edges[i][1]].push_back(make_pair(edges[i][0],edges[i][2]));
        }
        
        vector<vector<int>> ans(n);
        
        for(auto i=0;i<n;i++){
            
            vector<int> dist(n+1,INT_MAX);
            dist[i]=0;
            priority_queue<pair<int,int>> q;
            q.push(make_pair(0,i));
            
            while(!q.empty()){
                auto p = q.top();
                q.pop();
                int node = p.second;
                int nodedist = p.first;
                
                for(auto x : m[node]){
                    int checkdist = nodedist + x.second;
                    if(checkdist < dist[x.first]){
                        if(checkdist <= distanceThreshold and find(ans[i].begin(),ans[i].end(),x.first)==ans[i].end())
                            ans[i].push_back(x.first);
                        dist[x.first]= checkdist;
                        q.push(make_pair(dist[x.first],x.first));
                    }
                }
            }
        }
        
        int res=ans[0].size();
        int index=0;
        
        for(auto i=1;i<ans.size();i++){
            if(res>=ans[i].size()){
                res=ans[i].size();
                index = i;
            }
        }
        return index;
        
    }
};