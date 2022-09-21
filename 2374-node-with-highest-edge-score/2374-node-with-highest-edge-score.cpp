class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> graph(n,0);
        
        for(auto i=0;i<n;i++){
            graph[edges[i]]+=i;
        }
        
        vector<long long> ansidx;
        long long mx = INT_MIN;
        for(auto i=0;i<n;i++){
            if(graph[i]>mx){
                if(ansidx.empty()){
                    ansidx.push_back(i);
                }
                else{
                    ansidx.pop_back();
                    ansidx.push_back(i);
                }
                mx=graph[i];
            }
        }
        // for(auto x: graph){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        for(auto idx : ansidx){
            cout<<idx<<" ";
        }
        return ansidx[0];
    }
};