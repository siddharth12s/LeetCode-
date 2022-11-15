//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    

	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int m =grid.size();
	    int n=grid[0].size();
	    
	    vector<vector<int>> ans=grid;
	    vector<vector<int>> vis(m,vector<int>(n,0));
	    queue<pair<pair<int,int>,int>> q;

        
	    for(auto i=0;i<m;i++){
	        for(auto j=0;j<n;j++){
	            if(grid[i][j]==1){
	                q.push({{i,j},0});
	                vis[i][j]=1;
	            }
	            else{
	                vis[i][j]=0;
	            }
	        }
	    }
	    
	    int delr[]={-1,0,1,0};
	    int delc[]={0,-1,0,1};
	    
	    int steps=0;
	    while(!q.empty()){
	        int r = q.front().first.first;
	        int c = q.front().first.second;
	        int step = q.front().second;
	        q.pop();
	        ans[r][c]=step;
	        
	        for(auto i=0;i<4;i++){
	            int row = r + delr[i];
	            int col = c + delc[i];
	            
	            if(row>=0 and row<m and col>=0 and col<n and !vis[row][col]){
	                q.push({{row,col},step+1});
	                vis[row][col]=1;
	            }
	        }
	    }
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends