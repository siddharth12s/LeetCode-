class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size()>s2.size())
            return false;

        vector<int> s(26,0),p(26,0);

        for(auto i=0;i<s1.size();i++){
            s[s1[i]-'a']++;
            p[s2[i]-'a']++;
        }

        if(s==p){
            return true;
        }


        for(auto i=s1.size();i<s2.size();i++){

            p[s2[i]-'a']++;
            p[s2[i-s1.size()]-'a']--;

            if(s==p){
                return true;
            }
        }

        return false;
    }
};