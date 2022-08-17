class Solution {
public:

    int integerBreak(int n) {
        
        if(n<=2)
            return 1;
        
        if(n==3)    return 2;
        if(n==4)    return 4;
        
        int k = n/3;
        int m = n%3;
        if(m==0)    return pow(3,k);
        else if(m==1)   return pow(3,k-1)*4;
        else    return pow(3,k)*2;
    }
};