class Solution {
public:
    bool ends_with_vowel(string& key){
        
        int n = key.length();

        bool flag_start = false;
        bool flag_end = false;
        if(key[0]=='a' or key[0]=='e' or key[0]=='i' or key[0]=='o' or key[0]=='u'){
            flag_start=true;
        }
        if(key[n-1]=='a' or key[n-1]=='e' or key[n-1]=='i' or key[n-1]=='o' or key[n-1]=='u'){
            flag_end=true;
        }

        return flag_start && flag_end;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        vector<int> precheck;

        for(auto x : words){
            precheck.push_back(ends_with_vowel(x));
        }

        vector<int> presum(precheck.size()+1,0);

        for(auto i=1;i<=precheck.size();i++){
            presum[i] = presum[i-1] + precheck[i-1];
        }

        for(auto x : presum){
            cout<<x<<",";
        }

        vector<int> ans;
        for(auto x : queries){
            ans.push_back(presum[x[1]+1]-presum[x[0]]);
        }

        return ans;
    }
};