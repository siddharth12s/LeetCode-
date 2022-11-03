class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool check = next_permutation(nums.begin(),nums.end());
        
        if(!check)
            sort(nums.begin(),nums.end());
    }
};