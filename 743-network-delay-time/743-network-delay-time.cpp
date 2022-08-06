class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int,vector<pair<int,int>>> m;
        
        for(auto i=0;i<times.size();i++){
            m[times[i][0]].push_back(make_pair(times[i][1],times[i][2]));
            //m[times[i][1]].push_back(make_pair(times[i][0],times[i][2]));
        }
        
        
        vector<int> dist(n+1,INT_MAX);
        
        
        dist[k]=0;
        priority_queue<pair<int,int>> pq;
        pq.push(make_pair(0,k));
        
        while(!pq.empty()){
            auto p = pq.top();
            int node = p.second;
            int nodedist = p.first;
            pq.pop();
            
            for(auto i : m[node]){
                int k = nodedist + i.second;
                int nbr = i.first;
                if(k<dist[i.first]){
                    int dest = i.first;
                    dist[dest]=k;
                    pq.push(make_pair(dist[dest],dest));
                }
            }
        }
        
        int ans = INT_MIN;
        
        for(auto i=1;i<=n;i++){
            ans = max(ans,dist[i]);
        }
        
        if(ans==INT_MAX)    return -1;
        
        return ans;
        
        
    }
};