class Solution {
public:
    void perm(vector<int> &a,vector<vector<int>> &ans,vector<int> t,vector<bool> &chosen,int n){
        if(t.size()==n){
            ans.push_back(t);
            return;
        }
        else{
            for(auto i=0;i<n;i++){
                if(chosen[i]==true) continue;
                chosen[i]=true;
                t.push_back(a[i]);
                perm(a,ans,t,chosen,n);
                chosen[i]=false;
                t.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> t;
        vector<bool> chosen(n+1);
        perm(nums,ans,t,chosen,n);
        return ans;
    }
};