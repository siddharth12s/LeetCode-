class Solution {
public:
    void search(int y,bitset<30> &col,bitset<30> &diag1,bitset<30> &diag2,int &count,int n) {
            if (y == n) {
                count++;
                return;
            }
            for (int x = 0; x < n; x++) {
                    if (col[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
                    col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
                    search(y+1,col,diag1,diag2,count,n);
                    col[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
            }
    }
    int totalNQueens(int n) {
        int ans=0;
        bitset<30> col,diag1,diag2;
        search(0,col,diag1,diag2,ans,n);
        return ans;
    }
};