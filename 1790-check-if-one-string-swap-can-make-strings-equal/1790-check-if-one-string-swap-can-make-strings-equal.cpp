class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int c[26]={0}; int m=0;
        for(auto i=0;i<s1.length();i++){
            c[s1[i]-'a']++; c[s2[i]-'a']--;
        }
        for(auto i=0;i<26;i++){
            if(c[i]>0)
                return false;
        }
        for(auto i=0;i<s1.length();i++){
            if(s1[i]!=s2[i])
                m++;
        }
        return m<=2;
    }
};