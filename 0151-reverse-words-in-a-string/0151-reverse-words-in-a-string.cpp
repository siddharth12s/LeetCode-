class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> v;
        stringstream str(s);
        
        string word;
        while(str>>word){
            v.push_back(word);
        }
        s.clear();
        int i =v.size()-1;
        while(i>=0){
            s+=v[i];
            s+=" ";
            i--;
        }
        s.pop_back();
        return s;
    }
};