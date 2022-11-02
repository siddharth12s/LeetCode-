//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int x,int y,vector<vector<int>> &vis,vector<vector<int>> &m,int n){
        
        if( (x>=0 and x<n) and (y>=0 and y<n) and vis[x][y]==0 and m[x][y]==1)
            return true;
        else
            return false;
    }
    
    
    void solve(vector<vector<int>> &m,vector<vector<int>> &vis,int x,int y,vector<string>& ans,int n,string& path){
        if(x==n-1 and y==n-1){
            ans.push_back(path);
            return;
        }
        
        vis[x][y]=1;
        //down
        int newx = x+1;
        int newy = y;
        
        if(isSafe(newx,newy,vis,m,n)){
            path.push_back('D');
            solve(m,vis,x+1,y,ans,n,path);
            path.pop_back();
        }
        
        //up
         newx = x-1;
         newy = y;
        
        if(isSafe(newx,newy,vis,m,n)){
            path.push_back('U');
            solve(m,vis,x-1,y,ans,n,path);
            path.pop_back();
        }
        
        //left
        newx = x;
        newy = y-1;
        
        if(isSafe(newx,newy,vis,m,n)){
            path.push_back('L');
            solve(m,vis,x,y-1,ans,n,path);
            path.pop_back();
        }
        
        newx = x;
        newy = y+1;
        
        if(isSafe(newx,newy,vis,m,n)){
            path.push_back('R');
            solve(m,vis,x,y+1,ans,n,path);
            path.pop_back();
        }
        
        vis[x][y]=0;
        
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0]==0)
            return ans;
            
        
        vector<vector<int>> vis = m;
        for(auto i=0;i<n;i++){
            for(auto j=0;j<n;j++)
                vis[i][j]=0;
        }
        int x=0;
        int y=0;
        string path="";
        solve(m,vis,x,y,ans,n,path);
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends