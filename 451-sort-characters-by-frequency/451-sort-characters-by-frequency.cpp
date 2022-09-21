class Solution {
public:
    static bool comp(pair<char,int> p1,pair<char,int> p2){
        if(p1.second==p2.second)
            return p1.first<p2.first;
        
        return p1.second>p2.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(char c : s){
            m[c]++;
        }
        vector<pair<char,int>> v;
        for(auto x:m){
            v.push_back({x.first,x.second});
        }
        sort(v.begin(),v.end(),comp);
        
        
        int k=0;
        for(auto x : v){
            for(auto j=0;j<x.second;j++){
                s[k]=x.first;
                k++;
            }
        }
        return s;
    }
};