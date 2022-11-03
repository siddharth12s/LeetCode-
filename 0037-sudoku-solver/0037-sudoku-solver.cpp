class Solution {
public:
    
    bool canPlace(vector<vector<char>>& board,int i,int j,int x,int n){
        
        for(auto index=0;index<n;index++){
            if(board[index][j]==char(x+'0') or board[i][index]==char(x+'0'))
                return false;
        }
        
        //checking box
        int xs = sqrt(n);
        int srcx = (i/xs)*xs;
        int srcy = (j/xs)*xs;
        
        
        for(auto a=srcx;a<srcx+xs;a++){
            for(auto b=srcy;b<srcy+xs;b++){
                if(board[a][b]==char(x+'0'))
                    return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board,int i,int j,int n){
        
        //solved
        if(i==n){
            // for(auto a=0;a<n;a++){
            //     for(auto b=0;b<n;b++){
            //         cout<<board[a][b]<<" ";
            //     }
            //     cout<<endl;
            // }
            return true;
        }
        
        //if col over
        if(j==n){
           return solve(board,i+1,0,n);
        }
        
        // if place filled
        if(board[i][j]!='.'){
            return solve(board,i,j+1,n);
        }
        
        //check for number to be filled in this empty space
        
        for(auto x=1;x<=9;x++){
            if((canPlace(board,i,j,x,n))){
                board[i][j]=char(x+'0');
                bool canSolve = solve(board,i,j+1,n);
                if(canSolve)
                    return true;
            }
        }
        board[i][j]='.';
        return false;
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        bool check = solve(board,0,0,9);
    }
};