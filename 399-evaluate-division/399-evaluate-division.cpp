class Solution {
public:
    double dfs(string a , string b , unordered_set<string> & vis,unordered_map<string,vector<pair<string,double>>>& m){
        if(m.find(a)==m.end() or m.find(b)==m.end())  return -1;
        if(a==b)    return 1.0;
        
        for(auto x : m[a]){
            if(vis.count(x.first))  continue;
            vis.insert(x.first);
            double res = dfs(x.first,b,vis,m);
            if(res!=-1) return res*x.second;
        }
        return -1;
}
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        
        unordered_map<string,vector<pair<string,double>>> m;
        unordered_map<string,int> vis;
        
        for(auto i=0;i<n;i++){
            m[equations[i][0]].push_back({equations[i][1],values[i]});
            m[equations[i][1]].push_back({equations[i][0],(double)1/values[i]});
            vis[equations[i][0]]=0;
            vis[equations[i][1]]=0;
        }
        
        
        vector<double> ans;  
        int q = queries.size();
        
        for(auto x : queries){
            unordered_set<string> vis;
            ans.push_back(dfs(x[0],x[1],vis,m));
        }
        return ans;
    }
};