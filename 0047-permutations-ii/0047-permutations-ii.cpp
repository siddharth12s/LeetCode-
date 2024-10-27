class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> st;

    void solve(vector<int> &nums, int i,vector<int> &vis,vector<int> &temp){
        if(i==nums.size()){
            if(st.count(temp)==0){
                ans.push_back(temp);
                st.insert(temp);
            }
            return;
        }

        for(auto j=0;j<nums.size();j++){
            if(vis[j])  continue;
            vis[j]=1;
            temp.push_back(nums[j]);
            solve(nums,i+1,vis,temp);
            temp.pop_back();
            vis[j]=0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> vis(nums.size(),0);
        vector<int> temp;

        solve(nums,0,vis,temp);
        return ans;   
    }
};