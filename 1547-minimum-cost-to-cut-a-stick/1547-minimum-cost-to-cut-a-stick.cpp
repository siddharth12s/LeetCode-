class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m= cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        
        vector<vector<int>> dp(m+2,vector<int> (m+2,0));
        
        for(auto i=m;i>=1;i--){
            for(auto j=1;j<=m;j++){
                if(i>j)  continue;
                int mini=INT_MAX;
                for(auto k=i;k<=j;k++){
                    int cost=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    mini=min(mini,cost);
                }
                dp[i][j]=mini;
            }
        }
        
        // for(auto i=0;i<=m;i++){
        //     for(auto j=0;j<=m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[1][m];
    }
};