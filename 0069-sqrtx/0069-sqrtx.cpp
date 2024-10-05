class Solution {
public:
    int mySqrt(int x) {
        int start=1,end=x+1;
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