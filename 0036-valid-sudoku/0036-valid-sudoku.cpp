class Solution {
public:
    
    bool canPlace(vector<vector<char>>& board,int i,int j,char x,int n){
        
        for(auto ind=0;ind<n;ind++){
            if(board[ind][j]==x or board[i][ind]==x)
                return false;
        }
        
        int rn = sqrt(n);
        int nx = (i/rn)*rn;
        int ny = (j/rn)*rn;
        
        for(auto a = nx; a< nx+rn; a++){
            for(auto b = ny; b< ny+rn; b++){
                if(board[a][b]==x)
                    return false;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board,int i,int j,int n){
        
        //all rows solved
        if(i==n){
            return true;
        }
        
        //col solved check for row
        if(j==n){
            return solve(board,i+1,0,n);
        }
        
        if(board[i][j]=='.'){
            return solve(board,i,j+1,n);
        }
        
        //check which number can be filled
        char x = board[i][j];
        board[i][j]='.';
            
        if(canPlace(board,i,j,x,n)){
            board[i][j]=x;
            return solve(board,i,j+1,n);
        }
        board[i][j]=x;
        return false;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        bool check = solve(board,0,0,9);
        return check;
    }
};