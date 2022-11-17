class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> ans(m,vector<int>(n,-1));
        // vector<vector<int>> vis(m,vector<int>(n,0));
        
        queue<pair<int,int>> q;
        
        for(auto i=0;i<m;i++){
            for(auto j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        
        int dist=0;
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            
            int delr[]={0,-1,0,1};
            int delc[]={-1,0,1,0};
            
            
            for(auto i=0;i<4;i++){
                int newr = r+delr[i];
                int newc = c+delc[i];
                
                if(newr>=0 and newr<m and newc>=0 and newc<n and ans[newr][newc]==-1){
                    q.push({newr,newc});
                    ans[newr][newc] = ans[r][c]+1;
                }
            }
        }
        return ans;
    }
};