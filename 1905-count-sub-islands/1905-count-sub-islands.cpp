class Solution {
public:
    void dfs(vector<vector<int>> &grid2,int i,int j){
        int m = grid2.size();
        int n = grid2[0].size();
        if(i<0 or i>=m or j<0 or j>=n){
            return;
        }
        
        if(grid2[i][j]==0)
            return;
        
        grid2[i][j]=0;
        dfs(grid2,i+1,j);
        dfs(grid2,i,j+1);
        dfs(grid2,i-1,j);
        dfs(grid2,i,j-1);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        for(auto i=0;i<m;i++){
            for(auto j=0;j<n;j++){
                if(grid1[i][j]==0)
                    dfs(grid2,i,j);
            }
        }
        
        int ans=0;
        for(auto i=0;i<m;i++){
            for(auto j=0;j<n;j++){
                if(grid2[i][j]==1){
                    dfs(grid2,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};