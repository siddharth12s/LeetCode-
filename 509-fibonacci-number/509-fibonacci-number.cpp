class Solution {
public:
    int fib(int n) {
        if(n==0 or n==1)
            return n;
        int a=0,b=1,c=1;
        for(auto i=2;i<=n;i++){
            c=b+a;
            a=b;
            b=c;
        }
        return b;
    }
};