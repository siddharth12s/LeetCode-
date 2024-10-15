class Solution {
public:
    bool feasible(vector<int> &v, long long k, long long mid){
        long long cnt = 0;
        for(auto x : v){
            cnt += (long long)(x)/mid;
            if(cnt>=k)
                return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int start = 1, end=*max_element(candies.begin(),candies.end());
        int ans = 0;
        while(start<=end){
            long long mid = start + (end-start)/2;
            if(mid==0)
                break;
            if(feasible(candies,k,mid)){
                ans = mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};