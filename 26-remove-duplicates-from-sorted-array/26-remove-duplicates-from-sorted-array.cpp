class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        int j=0;
        for(auto i=0;i<nums.size();i++){
            if(s.count(nums[i])==0){
                nums[j]=nums[i];
                j++;
            }
            s.insert(nums[i]);
        }
        return s.size();
    }
};