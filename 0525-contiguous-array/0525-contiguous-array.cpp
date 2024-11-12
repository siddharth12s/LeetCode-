class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int sum = 0;
        unordered_map<int,int> seen{{0,-1}};
        int ans = 0;
        // last_index.push_back(0);
        for(int i=0;i<nums.size();i++){
            sum += nums[i]==1?1:-1;
            if(seen.count(sum)) ans=max(ans,i-seen[sum]);
            else    seen[sum]=i; 
        }

        return ans;
    }
};