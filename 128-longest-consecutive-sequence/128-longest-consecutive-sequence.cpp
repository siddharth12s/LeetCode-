class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int> res;
        int ans=0,prevans=0;
        sort(nums.begin(),nums.end());
        res.push_back(nums[0]);
        
        for(auto i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1)    res.push_back(nums[i]);
            else if(res[res.size()-1]==nums[i])    continue;
            else{
                        prevans=res.size();
                        ans=max(ans,prevans);
                        res.clear();
                        res.push_back(nums[i]);
                }
        }
        if(res.size()>=ans) return res.size();
        return ans;
    }
};