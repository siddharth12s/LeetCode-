class Solution {
public:
    
    void dfs(vector<vector<char>>& grid,vector<vector<int>> &vis,int row,int col,int m,int n){
        vis[row][col]=1;
        
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,-1,0,1};
        
        
        for(auto i=0;i<4;i++){
            int r = row + delrow[i];
            int c = col + delcol[i];
            
            if(r>=0 and r<m and c>=0 and c<n and grid[r][c]=='1' and !vis[r][c]){
                dfs(grid,vis,r,c,m,n);
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
                    dfs(grid,vis,i,j,m,n);
                }
            }
        }
        return cnt;
            
    }
};