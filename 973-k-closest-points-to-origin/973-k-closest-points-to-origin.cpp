class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<double,pair<int,int>>> pq;
        
        for(auto i=0;i<points.size();i++){
            double dist = sqrt((points[i][0]*points[i][0]) + (points[i][1]*points[i][1]));
            pq.push({-dist,{points[i][0],points[i][1]}});
        }
        vector<pair<int,int>> temp;
        while(k>0){
            cout<<pq.top().first<<endl;
            temp.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        vector<vector<int>> ans;
        for(auto x : temp){
            vector<int> t;
            t.push_back(x.first);
            t.push_back(x.second);
            ans.push_back(t);
        }
        return ans;
    }
};