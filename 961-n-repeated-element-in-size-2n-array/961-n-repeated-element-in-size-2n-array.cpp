class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        unordered_map<int,int> m;
        for(auto x : nums){
            m[x]++;
        }
        
        int n = nums.size()/2;
        int ans;
        for(auto x : m){
            if(x.second==n){
                ans=x.first;
                break;
            }
        }
        return ans;
    }
};