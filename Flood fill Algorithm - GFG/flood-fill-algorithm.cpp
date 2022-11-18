//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
       void dfs(vector<vector<int>> &grid,int i,int j,int chk,int color){
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 or i>=m or j<0 or j>=n or grid[i][j]==color or grid[i][j]!=chk)
            return;
        
        if(grid[i][j]==chk){
            grid[i][j]=color;
            dfs(grid,i+1,j,chk,color);
            dfs(grid,i,j+1,chk,color);
            dfs(grid,i-1,j,chk,color);
            dfs(grid,i,j-1,chk,color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
       vector<vector<int>> grid = image;
        int chk = image[sr][sc];
        dfs(grid,sr,sc,chk,newColor);
        return grid;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends