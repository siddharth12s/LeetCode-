class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int,int> m;
        int n=nums.size();
        
        for(auto i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(auto i=m.begin();i!=m.end();i++){
            if(i->second>1)
                return true;
        }
        return false;
    }
};