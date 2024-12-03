class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int i=0;

        for(auto x : spaces){
            string temp = s.substr(i,x-i);
            ans+=temp;
            ans+=" ";
            i=x;
        }
        ans+=s.substr(i,s.size()-i);
        return ans;
    }
};