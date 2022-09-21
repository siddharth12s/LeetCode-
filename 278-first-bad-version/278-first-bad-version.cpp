// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int ans;
        for(auto i=1;i<=n;i++){
            int x  = isBadVersion(i);
            if(x==1){
                ans=i;
                break;
            }
        }
        return ans;
    }
};