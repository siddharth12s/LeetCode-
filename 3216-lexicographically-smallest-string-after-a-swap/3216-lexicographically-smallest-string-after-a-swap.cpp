class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();

        string check = s;
        for(auto i=0;i<n-1;i++){
            if((s[i]-'0')%2==(s[i+1]-'0')%2){
                swap(s[i],s[i+1]);
                break;
            }
        }

        return s<check?s:check;
    }
};