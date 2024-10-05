class Solution {
public:
    int mySqrt(int x) {
        long long start=1, end=(long long)x+1;
        while(start<end){
            long long mid = start + (end-start)/2;
            if(mid*mid>x){
                end=mid;
            }else{
                start=mid+1;
            }
        }
        return start-1;
    }
};