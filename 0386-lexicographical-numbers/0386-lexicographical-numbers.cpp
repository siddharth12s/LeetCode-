class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;

        vector<string> str;
        for(auto i=1;i<=n;i++){
            str.push_back(to_string(i));
        }

        sort(str.begin(),str.end());

        for(auto ch : str){
            ans.push_back(stoi(ch));
        }

        return ans;
    }
};