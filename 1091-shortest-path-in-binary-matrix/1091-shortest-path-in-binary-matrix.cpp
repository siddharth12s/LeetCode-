class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0]==1 or grid[m-1][n-1]==1)
            return -1;
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> dis(m,vector<int> (n,0));
        
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0]=1;
        
        int delr[]={-1,0,1,0,-1,1,-1,1};
        int delc[]={0,-1,0,1,-1,1,1,-1};
        
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            
            for(auto i=0;i<8;i++){
                int x = f.first + delr[i];
                int y = f.second + delc[i];
                
                if(x>=0 and x<m and y>=0 and y<n and grid[x][y]==0 and !vis[x][y]){
                    q.push({x,y});
                    dis[x][y]=dis[f.first][f.second]+1;
                    vis[x][y]=1;
                }
            }
        }
        if(!vis[m-1][n-1])
            return -1;
        return dis[m-1][n-1]+1;
    }
};