class Solution {
public:
    int possible(vector<int> &v, int day,int m, int k){
        int cnt = 0;
        int check = 0;
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
        if(m*k>bloomDay.size())
            return -1;

        vector<int> temp = bloomDay;
        sort(temp.begin(),temp.end());

        int ans = -1;
        int start = 0, end = bloomDay.size()-1;

        while(start<end){
            int mid = start+ (end-start)/2;
            if(possible(bloomDay,temp[mid],m,k)){
                end=mid;
            }else{
                start=mid+1;
            }
        }

        return temp[start];
    }
};