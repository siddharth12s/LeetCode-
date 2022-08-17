class Solution {
public:
    void f(vector<int>& c, vector<vector<int>>& ans, int i, int tar,vector<int>& r){
        
        if(tar==0){
            ans.push_back(r);
            //r.clear();
            return;
        }
        
        if(tar<0 or i==c.size())    return;
        
            
            r.push_back(c[i]);
            f(c,ans,i,tar-c[i],r);
            r.pop_back();
            f(c,ans,i+1,tar,r);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        
        vector<vector<int>> ans;
        vector<int> t;
        f(candidates,ans,0,target,t);
        return ans;
        
    }
};