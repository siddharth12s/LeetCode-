class Solution {
public:
    int count_ones(vector<int> &m){
        int start=0,end=m.size()-1;

        while(start<=end){
            int mid=start+(end-start)/2;
            if(m[mid]==0){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return start;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // vector<int> m(mat.size(),0);
        priority_queue<pair<int,int> ,vector<pair<int,int>>> pq;

        for(auto i=0;i<mat.size();i++){
            int cnt=count_ones(mat[i]);
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