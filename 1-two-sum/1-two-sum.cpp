class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        
        int n = nums.size();
        
        vector<int> ans;
        
        for(auto i=0;i<n;i++){
            int x= target-nums[i];
            
            if(m.find(x)!=m.end()){
                ans.push_back(m[x]);
                ans.push_back(i);
                return ans;
            }
            else
                m[nums[i]]=i;
        }
        return ans;
    }
};