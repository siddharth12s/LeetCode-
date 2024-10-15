class Solution {
public:
    bool feasible(vector<int> &v, int n, long long mid){
        long long cnt = 0;
        for(auto x : v){
            cnt += (long long)((x+mid-1))/mid;
            if(cnt>n)
                return true;
        }
        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        long long start =1, end=0;
        for(auto &x : quantities){
            end += x;
        }


        while(start<=end){
            auto mid = start+(end-start)/2;
            if(feasible(quantities,n,mid)){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }

        return start;
    }
};