class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        
        for(string &s : strs){
            string temp =s;
            sort(temp.begin(),temp.end());
            
            m[temp].push_back(s);
        }
        
        vector<vector<string>> ans(m.size());
        int i=0;
        for(auto x : m){
            for(auto s : x.second){
                ans[i].push_back(s);
            }
            i++;
        }
        
        return ans;
    }
};