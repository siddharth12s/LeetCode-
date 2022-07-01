class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> t(n+1,0);
        for(auto el : trust){
            t[el[0]]--;
            t[el[1]]++;
        }
        for(auto i=1;i<=n;i++){
            if(t[i]==n-1)
                return i;
        }
        return -1;
    }
};