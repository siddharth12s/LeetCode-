class Solution {
public:
    int minLength(string s) {
        vector<char> st;

        for(auto ch : s){
            if(st.size()==0){
                st.push_back(ch);
                continue;
            }

            if((ch=='B' && st.back()=='A') || (ch=='D' && st.back()=='C')){
                st.pop_back();
            }else{
                st.push_back(ch);
            }
        }
        return st.size();
    }
};