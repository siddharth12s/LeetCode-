class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) {
        
       // sort(c.begin(),c.end());
        set<int> s;
        int n = c.size();
        
        if(n%2)
            return {};
        
        unordered_map<int,int> m;
        for(auto i=0;i<n;i++){
            m[c[i]]++;
        }
        
        vector<int> ans;
        sort(c.begin(),c.end());
        for(auto x : c){
            if(m[x]==0) continue;
            if(m[2*x]==0)   return {};
            ans.push_back(x);
            m[x]--;
            m[2*x]--;
        }
        
        return ans;
        
        // return {}; 
    }
};