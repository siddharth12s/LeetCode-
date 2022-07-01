class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> graph(n+1);
        for(auto el : trust){
            graph[el[0]].push_back(el[1]);
        }
        int ans=-1;
        for(auto i=1;i<=n;i++){
            if(graph[i].size()==0)
                ans = i;
        }
        for(auto i=1;i<=n;i++){
            if(i==ans)
                continue;
            
            if(find(graph[i].begin(),graph[i].end(),ans)==graph[i].end()){
                ans=-1;
                break;
            }
        }
        return ans;
    }
};