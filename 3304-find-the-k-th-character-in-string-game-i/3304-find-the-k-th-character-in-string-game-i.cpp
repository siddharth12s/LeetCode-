class Solution {
public:
    char kthCharacter(int k) {
        int cnt = 0;
        k-=1;
        while(k){
            if(k&1)
                cnt++;

            k>>=1;
        }

        return char('a' + cnt);
    }
};