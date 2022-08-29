class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1)    return true;
        if(!n) return false;
        
        return isPowerOfTwo(n/2) and n%2==0;
    }
};