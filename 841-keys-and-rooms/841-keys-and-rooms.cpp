class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int cnt=1;
        int n = rooms.size();
        unordered_set<int> keys;
        vector<int> vis(n,0);
        
        for(auto x : rooms[0])
            keys.insert(x);
        vis[0]=1;
        while(!keys.empty()){
            cnt++;
            int i = *keys.begin();
            vis[i]=1;
            for(auto x : rooms[i]){
                if(!vis[x])
                    keys.insert(x);
            }
            keys.erase(i);
        }
        
        return cnt==n;
    }
};