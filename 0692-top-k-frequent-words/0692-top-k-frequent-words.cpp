struct Compare{
    bool operator()(pair<string,int> &p1,pair<string,int> &p2){
        if(p1.second==p2.second){
            return p1.first>p2.first;
        }
        return p1.second<p2.second;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string,int> m;
        priority_queue<pair<string,int>, vector<pair<string,int>>,Compare > pq;

        for(auto x : words){
            m[x]++;
        }

        for(auto x : m){
            pq.push({x.first,x.second});
        }

        while(!pq.empty() and k>0){
            auto check = pq.top();
            ans.push_back(check.first);
            k--;
            pq.pop();
        }

        return ans;
    }
};