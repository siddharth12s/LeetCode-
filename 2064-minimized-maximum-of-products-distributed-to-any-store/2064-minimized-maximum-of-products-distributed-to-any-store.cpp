class Solution {
public:
    bool feasible(vector<int> &v, int n, int mid){
        int cnt = 0;
        for(auto x : v){
            cnt += (x+mid-1)/mid;
            if(cnt>n)
                return true;
        }
        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int start =1, end=0;
        for(auto &x : quantities){
            end += x;
        }

        
        while(start<=end){
            int mid = start+(end-start)/2;
            if(feasible(quantities,n,mid)){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }

        return start;
    }
};