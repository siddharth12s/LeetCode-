class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        unordered_map<int,vector<pair<int,double>>> m;

        for(auto i=0;i<edges.size();i++){
                m[edges[i][0]].push_back(make_pair(edges[i][1],log10(succProb[i])));
                m[edges[i][1]].push_back(make_pair(edges[i][0],log10(succProb[i])));
        }

        unordered_map<int,double> dist;
        
      /*  for(auto j:m){
            cout<<j.first<<"->";
            for(auto x : j.second){
                cout<<"( node "<<x.first<<" is at dist = "<<x.second<<")";
            }
            cout<<endl;
        }*/
    
        
        for(auto j:m){
            dist[j.first]=INT_MIN;
        }
        
        priority_queue<pair<double,int>> pq;
        dist[start]=0;
        pq.push(make_pair(0,start));
        
        while(!pq.empty()){
            
            auto p = pq.top();
            int node = p.second;
            
            double nodedist=(p.first);
            pq.pop();
           // cout<<p.first<<" "<<p.second<<endl;
            
            for(auto nbr: m[node]){
                double k = nodedist + nbr.second;
                if(k > dist[nbr.first]){
                    int dest= nbr.first;
                    dist[dest] = k;
                    pq.push(make_pair(dist[dest],dest));
                }
            }
        }
        double ans=0;
        for(auto d : dist){
            if(d.first==end)
                ans= d.second;
        }
        
       /* for(auto d : dist){
            cout<<d.first<<" is at dist = "<<d.second<<endl;
        }*/
        if(ans==0)    return 0;
        return pow(10,ans);
    }
};