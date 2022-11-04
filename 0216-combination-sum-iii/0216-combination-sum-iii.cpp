class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> &s, int i,int n,int k,int sum){
        if(s.size()==k and n==sum){
                ans.push_back(s);
                return;
            }
        else if (s.size()>k or n<0)
            return;
        
        for(auto j=i;j<=9;j++){
            sum += j;
            s.push_back(j);
            solve(ans,s,j+1,n,k,sum);
            sum -=j;
            s.pop_back();
            // solve(ans,s,j+1,n,k,sum);

        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> s;
        
        solve(ans,s,1,n,k,0);
        return ans;
        
    }
};