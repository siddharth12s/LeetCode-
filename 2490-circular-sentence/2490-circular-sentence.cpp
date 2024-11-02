class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        vector<string> v;
        string word;
        while(ss>>word){
            v.push_back(word);
        }

        for(auto i=1;i<v.size();i++){
            if(v[i-1].back()!=v[i][0])
                return false;
        }

        if(v[0][0]!=v[v.size()-1].back())
            return false;
        return true;
    }
};