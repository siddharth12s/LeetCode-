class Solution {
public:
    
    void bfs(vector<vector<char>>& grid,vector<vector<int>> &vis,int row,int col,int m,int n){
        vis[row][col]=1;
        
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,-1,0,1};
        queue<pair<int,int>> q;
        q.push({row,col});
        
        while(!q.empty()){
                
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(auto i=0;i<4;i++){
                    int r = x + delrow[i];
                    int c = y + delcol[i];

                    if(r>=0 and r<m and c>=0 and c<n and grid[r][c]=='1' and !vis[r][c]){
                        vis[r][c]=1;
                        q.push({r,c});
                    }
                }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m,(vector<int> (n,0)));
        
        int cnt=0;
        for(auto i=0;i<m;i++){
            for(auto j=0;j<n;j++){
                
                if(grid[i][j]=='1' and !vis[i][j]){
                    cnt++;
                    bfs(grid,vis,i,j,m,n);
                }
            }
        }
        return cnt;
            
    }
};