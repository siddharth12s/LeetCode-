class Solution {
public:
    static bool compare(pair<int,int> &p1, pair<int,int> &p2){
        if(p1.first==p2.first)
            return p1.second<p2.second;

        return p1.first<p2.first;
    }
    int maxEvents(vector<vector<int>>& events) {
        
        vector<pair<int,int>> v;

        for(auto x : events){
            v.push_back({x[0],x[1]});
        }

        sort(v.begin(),v.end(),compare);

        int cnt = 1;
        auto prev = v[0];
        for(auto i=1;i<v.size();i++){

            if(prev.second <= v[i].first or prev.second <= v[i].second){
                cnt++;
            }
            cout<<prev.first<<","<<prev.second<<endl;
            prev = v[i];
        }

        return cnt;
    }
};