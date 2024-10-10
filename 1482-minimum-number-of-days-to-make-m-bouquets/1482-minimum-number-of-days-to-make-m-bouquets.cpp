class Solution {
public:
    int possible(vector<int> &v, int day,int m, int k){
        int cnt = 0;
        long long check = 0;
        for(auto x : v){
            if(x<=day){
                cnt++;
            }else{
                check += cnt/k;
                cnt=0;
            }
        }

        check += cnt/k;
        return check>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*(long long)k>bloomDay.size())
            return -1;

        int maxi = *max_element(bloomDay.begin(),bloomDay.end());
        int mini = *min_element(bloomDay.begin(),bloomDay.end());


        int ans = -1;
        int start = mini, end = maxi;

        while(start<=end){
            int mid = start+ (end-start)/2;
            if(possible(bloomDay,mid,m,k)){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }

        return start;
    }
};