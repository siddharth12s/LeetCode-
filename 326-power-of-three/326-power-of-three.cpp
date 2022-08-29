class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1)    return true;
        if(!n)  return false;
        
        return isPowerOfThree(n/3) and n%3==0;
    }
};