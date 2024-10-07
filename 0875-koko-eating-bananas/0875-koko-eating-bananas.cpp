class Solution {
public:
    bool isfeasible(vector<int> &v,int &k, int &h){
        int hours = 0;
        for(auto x : v){
            int div = x/k;
            hours+=div;
            if(x%k){
                hours++;
            }

            if(hours>h)
                return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1,end=1e9;

        while(start<end){
            int mid = start +(end-start)/2;
            if(isfeasible(piles,mid,h)){
                end=mid;
            }else{
                start=mid+1;
            }
        }

        return start;
    }
};