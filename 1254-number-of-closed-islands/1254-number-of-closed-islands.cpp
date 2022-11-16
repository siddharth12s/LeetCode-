class Solution {
public:
    void dfs(vector<vector<int>> & grid,vector<vector<int>> &vis,int i,int j){
        
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]!=0 or vis[i][j])
            return;
        
        vis[i][j]=1;
        dfs(grid,vis,i+1,j);
        dfs(grid,vis,i-1,j);
        dfs(grid,vis,i,j+1);
        dfs(grid,vis,i,j-1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        for(auto i=0;i<m;i++){
            for(auto j= 0;j<n;j++){
                if(i==0 or i==m-1 or j==0 or j==n-1){
                    if(grid[i][j]==0)
                        dfs(grid,vis,i,j);
                }
            }
        }
        
        int ans=0;
        for(auto i=0;i<m;i++){
            for(auto j=0;j<n;j++){
                if(grid[i][j]==0 and !vis[i][j]){
                    ans++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return ans;
    }
};