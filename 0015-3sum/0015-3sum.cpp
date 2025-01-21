class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        unordered_map<int,int> mp1;
        set<vector<int>> st;
        for(auto i=0;i<n-2;i++){
            mp1[nums[i]] = i;
            unordered_map<int,int> mp2;
            int target = -1*nums[i];
            for(auto j=i+1;j<n;j++){
                if(mp2.find(target-nums[j])!=mp2.end()){
                    vector<int> temp = {nums[i],target-nums[j],nums[j]};
                    sort(temp.begin(),temp.end());
                    if(st.count(temp)==0){
                        st.insert(temp);
                        ans.push_back(temp);
                    }
                }
                mp2[nums[j]]=j;
            }
        }



        return ans;
    }
};