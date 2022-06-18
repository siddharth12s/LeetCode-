// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
int mod = 1003;
class Solution{
public:
     int countWays(int N, string S){
        vector<vector<vector<int>>> ways(N,vector<vector<int>>(N,vector<int>(2,0)));
        
        // base cases
        for(int i=0;i<N;i+=2) {
            ways[i][i][1] = (S[i] == 'T');
            ways[i][i][0] = (S[i] == 'F');
        }
        
        for(int i=N-3;i>=0;i--) {
            for(int j=i+2;j<N;j++) {
                for(int isTrue=0;isTrue<2;isTrue++) {
                    int ans = 0;
                    for(int k=i+1;k<j;k+=2) {
                        
                        // four elements required
                        int leftFalse = ways[i][k-1][0] % mod, rightFalse = ways[k+1][j][0] % mod;
                        int leftTrue = ways[i][k-1][1] % mod, rightTrue = ways[k+1][j][1] % mod;
                        
                        int operations;
                        
                        // four possible combinations
                        int a = (leftTrue * rightTrue) % mod;
                        int b = (leftTrue * rightFalse) % mod;
                        int c = (leftFalse * rightTrue) % mod;
                        int d = (leftFalse * rightFalse) % mod;
                        int total = (a + b + c + d) % mod;
                        
                        if(S[k] == '&') {
                            operations = a;
                            operations %= mod;
                        } else if(S[k] == '|') {
                            operations = a + b + c;
                            operations %= mod;
                        } else {
                            operations = b + c;
                            operations %= mod;
                        }
                        
                        // if we want false we calculate true ways and substact from total
                        if(!isTrue) {
                            int temp = total - operations;
                            temp += (mod * mod);
                            temp %= mod;
                            operations = temp;
                        }
                        
                        ans += operations;
                        ans %= mod;
                    }
                    
                    ways[i][j][isTrue] = ans;
                }
            }
        }
        
        return ways[0][N-1][1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends