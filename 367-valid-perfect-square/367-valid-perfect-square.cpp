class Solution {
public:
    bool isPerfectSquare(int num) {
        unsigned long long l =1;
        unsigned long long r = num;
        
        while(l<=r){
            unsigned long long m = l + (r-l)/2;
            
            if(m*m>num)
                r=m-1;
            else if(m*m<num)
                l=m+1;
            else
                return true;
        }
        return false;
    }
};