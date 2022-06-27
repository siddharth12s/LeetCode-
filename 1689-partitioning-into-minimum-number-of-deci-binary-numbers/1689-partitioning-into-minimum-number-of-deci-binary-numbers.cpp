class Solution {
public:
    int minPartitions(string n) {
        int l=n.length();
        int ans= n[0]-'0';
        for(auto i=1;i<l;i++){
            ans = max(ans,n[i]-'0');
        }
        return ans;
    }
};