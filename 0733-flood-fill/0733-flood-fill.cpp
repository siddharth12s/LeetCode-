class Solution {
public:
    
    void dfs(vector<vector<int>> &grid,int i,int j,int chk,int color){
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 or i>=m or j<0 or j>=n or grid[i][j]==color or grid[i][j]!=chk)
            return;
        
        if(grid[i][j]==chk){
            grid[i][j]=color;
            dfs(grid,i+1,j,chk,color);
            dfs(grid,i,j+1,chk,color);
            dfs(grid,i-1,j,chk,color);
            dfs(grid,i,j-1,chk,color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<vector<int>> grid = image;
        int chk = image[sr][sc];
        dfs(grid,sr,sc,chk,color);
        return grid;
    }
};