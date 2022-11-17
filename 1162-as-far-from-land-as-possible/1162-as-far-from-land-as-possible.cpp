class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>> q;
        
        for(auto i=0;i<m;i++){
            for(auto j=0;j<n;j++){
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }
        
        if(q.size()==m*n)
            return -1;
        
        int dist=0;
        while(!q.empty()){
            int size = q.size();
            dist++;
            while(size--){
                int delr[] = {0,-1,0,1};
                int delc[] = {1,0,-1,0};
                
                auto [si,sj]=q.front();
                q.pop();
                
                for(auto i=0;i<4;i++){
                    int newi = si + delr[i];
                    int newj = sj + delc[i];
                    
                    if(newi>=0 and newi<m and newj>=0 and newj<n and grid[newi][newj]==0){
                        q.push({newi,newj});
                        grid[newi][newj]=1;
                    }
                }
            }
        }
        return dist-1;
    }
};