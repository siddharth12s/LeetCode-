class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int,int> m;
        int n=nums.size();
        
        for(auto i : nums){
            m[i]++;
        }
        for(auto i : m){
            if(i.second>1)
                return true;
        }
        return false;
    }
};