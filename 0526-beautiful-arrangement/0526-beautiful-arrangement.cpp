class Solution {
public:
    void solve(vector<int> &nums,int i,int n,int &ans){
        if(i==n){
            ans++;
            return;
        }
        
        for(auto j=i;j<n;j++){
            if(nums[j]%(i+1)==0 or (i+1)%nums[j]==0){
            swap(nums[i],nums[j]);
            solve(nums,i+1,n,ans);
            swap(nums[i],nums[j]);
            }
        }
    }
    int countArrangement(int n) {
        vector<int> nums;
        for(auto i=1;i<=n;i++)
            nums.push_back(i);
        
        int ans=0;
        solve(nums,0,n,ans);
        return ans;
    }
};