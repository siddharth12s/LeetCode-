class Solution {
public:

    void dfs(vector<vector<char>> &grid,int m, int n, int i, int j){
        if(i<0 or j<0 or i>=m or j>=n){
            return;
        }

        if(grid[i][j]=='0')
            return;

        grid[i][j]='0';
        dfs(grid,m,n,i+1,j);
        dfs(grid,m,n,i,j+1);
        dfs(grid,m,n,i-1,j);
        dfs(grid,m,n,i,j-1);

    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> (m,vector<int>(n,0));

        int ans = 0;
        for(auto i=0;i<m;i++){
            for(auto j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,m,n,i,j);
                    ans++;
                }
            }
        }

        return ans;
    }
};