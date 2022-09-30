class Solution {
public:
    int reverse(int x) {
        
       long long ans=0;
        while(x){
            if(((ans*10)>INT_MAX) or ((ans*10)<INT_MIN))
                return 0;
            else{
                ans = ans*10 + x%10;
                x/=10;
            }
        }
        
        
        return ans;
    }
};