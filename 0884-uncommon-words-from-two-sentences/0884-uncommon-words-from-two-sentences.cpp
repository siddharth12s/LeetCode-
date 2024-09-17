class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> st;

        stringstream s(s1);
        string word;
        while(s>>word){
            st[word]++;
        }

        vector<string> ans;
        
        stringstream ss(s2);
        word = "";
        while(ss>>word){
            st[word]++;
        }

        for(auto [word,val] : st){
            if(val==1)
                ans.push_back(word);
        }

        return ans;
    }
};