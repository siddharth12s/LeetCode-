class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1){
            if(k==1)
                return 0;
            else
                return 1;
        }
        if(k%2) return kthGrammar(n-1,(k+1)/2);
        return kthGrammar(n-1,k/2)?0:1;
    }
};