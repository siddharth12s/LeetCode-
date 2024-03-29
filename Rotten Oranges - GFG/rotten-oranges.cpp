//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int m=grid.size();
        int n=grid[0].size();
        
        // vector<vector<int>> vis(m,vector,int> (n,0));
        
        queue<pair<int,int>> q;
        int fresh=0;
        for(auto i=0;i<m;i++){
            for(auto j=0;j<n;j++){
                if(grid[i][j]==2){
                    // grid[i][j]=-1;
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        
        int ans=-1;
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                int si=q.front().first;
                int sj=q.front().second;
                q.pop();
                
                int delr[]={-1,0,1,0};
                int delc[]={0,-1,0,1};
                
                for(auto i=0;i<4;i++){
                    int r = si + delr[i];
                    int c = sj + delc[i];
                    
                    if(r>=0 and r<m and c>=0 and c<n and grid[r][c]==1){
                        q.push({r,c});
                        grid[r][c]=2;
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

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends