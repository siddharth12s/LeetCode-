class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // vector<int> m(mat.size(),0);
        priority_queue<pair<int,int> ,vector<pair<int,int>>> pq;

        for(auto i=0;i<mat.size();i++){
            int cnt=0;
            for(auto y : mat[i]){
                if(y==1)
                    cnt++;
            }
            pq.push({cnt,i});
            if(pq.size()>k)
                pq.pop();
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};