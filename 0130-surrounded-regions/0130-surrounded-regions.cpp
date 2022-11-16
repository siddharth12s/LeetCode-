class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>> &vis,int i,int j){
        
        if(i<0 or i>=board.size() or j<0 or j>=board[0].size() or board[i][j]=='X' or vis[i][j])
            return;
       
        if(board[i][j]=='O')
            vis[i][j]=1;
        
        dfs(board,vis,i+1,j);
        dfs(board,vis,i,j+1);
        dfs(board,vis,i-1,j);
        dfs(board,vis,i,j-1);
    }
    
    
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        for(auto i=0; i<m;i++){
            for(auto j=0;j<n;j++){
                if(i==0 or i==m-1 or j==0 or j==n-1){
                       if(board[i][j]=='O'){
                        dfs(board,vis,i,j);
                    }
                }
            }
        }
        
        for(auto i=0;i<m;i++){
            for(auto j=0;j<n;j++){
                if(board[i][j]=='O' and !vis[i][j])
                    board[i][j]='X';
            }
        }
    }
};