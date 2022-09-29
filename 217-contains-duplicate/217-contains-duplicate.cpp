class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> a;
        for(auto i=0;i<nums.size();i++){
            if(a.count(nums[i]))
                return true;
            else
                a.insert(nums[i]);
        }
        return false;
    }
};