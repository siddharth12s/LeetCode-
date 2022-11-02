class Solution {
public:
    
    void solve(vector<int> &c,vector<vector<int>> &ans,int i,int n,int t,set<vector<int>>& temp,vector<int> & v){
        
        if(i==n and t!=0){
            return;
        }
        
        
        if(t==0){
            
            if(temp.count(v)==0){
                ans.push_back(v);
                temp.insert(v);
                return;
            }
            return;
        }
        if(c[i]>t)  return;
        
        for(auto j=i;j<n;j++){
                if(j!=i and c[j]==c[j-1])
                    continue;
                v.push_back(c[j]);
                solve(c,ans,j+1,n,t-c[j],temp,v);
                v.pop_back();
                // solve(c,ans,i+1,n,t,temp,v);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(),c.end());
        vector<vector<int>> ans;
        set<vector<int>> temp;
        vector<int> v;
        int n = c.size();
        
        solve(c,ans,0,n,target,temp,v);
        return ans;
    }
};