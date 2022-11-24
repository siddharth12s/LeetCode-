class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int m = maze.size();
        int n = maze[0].size();
        
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int dis =1 ;
        
        while(!q.empty()){
            
            int size= q.size();
            dis++;
            while(size--){
                
                auto [si,sj]=q.front();
                q.pop();
                
                int delr[]={-1,0,1,0};
                int delc[]={0,-1,0,1};
                
                for(auto i=0;i<4;i++){
                    int x = si + delr[i];
                    int y = sj + delc[i];
                    
                    if(x<0 || y<0 || x>=m || y>=n || maze[x][y]=='+')
                        continue;
					//if we have reached the exit then current moves are the min moves to reach the exit
                    if(x==0 || y==0 || x==m-1 || y==n-1)
                        return dis-1;
                    
                    maze[x][y]='+';
                    q.push({x,y});
                    
                    
                }
            }
        }
        return -1;
        
    }
};