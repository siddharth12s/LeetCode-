class Solution {
public:
    int bfs(vector<vector<int>> &graph){
        int n = graph.size();
        vector<int> dist(n,1e9);
        dist[0]=0;
        priority_queue<pair<int,int>> pq;
        pq.push({0,0});

        while(!pq.empty()){
            auto node = pq.top().second;
            int nodedist = pq.top().first;
            pq.pop();


            for(auto nbr : graph[node]){
                int check_dist = nodedist + 1;
                if(check_dist<=dist[nbr]){
                    dist[nbr] = check_dist;
                    pq.push({check_dist,nbr});
                }
            }
        }

        return dist[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);

        for(auto i=0;i<n-1;i++){
            graph[i].push_back(i+1);
        }
        vector<int> ans;
        auto E = queries[0];
        for(auto E : queries){
            graph[E[0]].push_back(E[1]);
            int check = bfs(graph);
            ans.push_back(check);
        }

        // graph[E[0]].push_back(E[1]);

        // vector<int> vis(n,0);

        // int check = bfs(graph,vis);
        // ans.push_back(check);

        return ans;
    }
};