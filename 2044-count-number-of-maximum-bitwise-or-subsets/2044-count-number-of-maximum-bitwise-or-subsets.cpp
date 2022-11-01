class Solution {
public:
    void solve(vector<int>& sub,vector<int> &nums,int i,int& x,set<int>&s,int &ans){
        
        if(i==nums.size()){
            int xr = 0;
            if(sub.size()==0)
                return;
            for(auto a : sub){
                xr |= a;
            }
            // cout<<xr<<endl;
            if(xr>=x){
                if(s.count(xr)){
                    ans++;
                }else{
                    ans=1;
                    x=xr;
                    s.insert(xr);
                }
            }
            return;
        }
        
        sub.push_back(nums[i]);
        solve(sub,nums,i+1,x,s,ans);
        sub.pop_back();
        solve(sub,nums,i+1,x,s,ans);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> sub;
        set<int> s;
        int ans=0;
        int x = INT_MIN;
        solve(sub,nums,0,x,s,ans);
        // cout<<ans;
        return ans;
    }
};