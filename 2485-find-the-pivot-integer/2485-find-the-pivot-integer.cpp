class Solution {
public:
    int pivotInteger(int n) {
        vector<int> prefix(n+1,0), suffix(n+2,0);


        for(auto i=1;i<=n;i++){
            prefix[i] = prefix[i-1] + i;
        }

        for(auto i=n;i>=1;i--){
            suffix[i] = suffix[i+1] + i;
        }

        for(auto i=1;i<=n;i++){
            if(suffix[i]==prefix[i])
                return i;
        }

        return -1;
    }
};