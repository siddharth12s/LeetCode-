class Solution {
public:
    
    void dfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int row,int col,int &cnt){
        
        vis[row][col]=1;
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        int m = grid.size();
        int n =  grid[0].size();
        
        for(auto i=0;i<4;i++){
            int r = row + delrow[i];
            int c = col + delcol[i];
            
            if(r>=0 and r<m and c>=0 and c<n and grid[r][c]==1 and !vis[r][c]){
                cnt++;
                dfs(grid,vis,r,c,cnt);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        int maxArea = INT_MIN;
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        for(auto i=0;i<m;i++){
            for(auto j=0;j<n;j++){
                if(grid[i][j]==1 and !vis[i][j]){
                    int cnt=1;
                    dfs(grid,vis,i,j,cnt);
                    maxArea=max(cnt,maxArea);
                }
            }
        }
        return maxArea==INT_MIN?0:maxArea;
    }
};