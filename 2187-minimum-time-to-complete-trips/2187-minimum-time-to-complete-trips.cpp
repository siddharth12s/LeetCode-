class Solution {
public:
    bool feasible(vector<int> &v, int t, long long mid){
        long long cnt = 0;
        for(auto &x : v){
            cnt += mid/x;
            if(cnt>=t)
                return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long start=1;
        long long end = 1e14;
        // for(auto x : time){
        //     end += x;
        // }

        while(start<=end){
            auto mid = start + (end-start)/2;
            if(feasible(time,totalTrips,mid)){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return start;
    }
};