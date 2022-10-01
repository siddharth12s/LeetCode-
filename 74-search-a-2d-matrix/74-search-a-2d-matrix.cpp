class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int colm = matrix[0].size()-1;
        
        int row = 0;
        int col = colm;
        
        while(row<rows and col>-1){
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]>target)
                col--;
            else
                row++;
        }
        
        return false;
    }
};