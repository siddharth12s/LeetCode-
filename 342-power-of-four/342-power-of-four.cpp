class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1)    return true;
        if(!n)  return false;
        
        return isPowerOfFour(n/4) and n%4==0;
    }
};