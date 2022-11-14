class Solution {
public:
   
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        
        int fresh=0;
        queue<pair<int,int>> q;
        for(auto i=0;i<m;i++){
            for(auto j=0;j<n;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        
        
        int delr[] = {-1,0,1,0};
        int delc[] = {0,-1,0,1};
        
        int ans=-1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto p = q.front();
                q.pop();

                for(auto a=0;a<4;a++){
                    int x = p.first + delr[a];
                    int y = p.second + delc[a];

                    if(x>=0 and x<m and y>=0 and y<n and grid[x][y]==1){
                        grid[x][y]=2;
                        q.push({x,y});
                        fresh--;
                    }
                }
            }
            ans++;
        } 
        
        if(fresh>0) return -1;
        if(ans==-1) return 0;
        return ans;
    }
};