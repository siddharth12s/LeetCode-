class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        map<int,int> lost;
        
        for(auto x : matches){
            if(lost.find(x[0])==lost.end())
                lost[x[0]]=0;
            lost[x[1]]++;
        }
        
        vector<int> zero,one;
        
        for(auto &x : lost){
            
            auto [i,j] = x;
            
            if(j==0)    zero.push_back(i);
            if(j==1)    one.push_back(i);
        }
        
        return {zero,one};
    }
};