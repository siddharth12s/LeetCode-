class Solution {
public:
    
    void dfs(vector<vector<int>> &grid,int i,int j){
        
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]!=1)
            return;
        
        grid[i][j]=2;
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
    }
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        // vector<vector<int>> vis(m,vector<int> (n,0));
        // queue<pair<int,int>> q;
        int flag=0;
        
        for(auto i=0;i<m;i++){
            for(auto j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j);
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
        }
        
        vector<pair<int,int>> p1,p2;
        
        for(auto i=0;i<m;i++){
            for(auto j=0;j<n;j++){
                if(grid[i][j]==2)
                    p1.push_back({i,j});
                else if(grid[i][j]==1)
                    p2.push_back({i,j});
            }
        }
        
        int mindis = INT_MAX;
        
        for(auto i=0;i<p1.size();i++){
            for(auto j=0;j<p2.size();j++){
                int chk = abs(p1[i].first-p2[j].first) + abs(p1[i].second-p2[j].second);
                mindis = min(mindis,chk);
            }
        }
        
        return mindis-1;
        
    }
};