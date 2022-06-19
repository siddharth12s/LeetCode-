class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i=0;s[i]!='\0';i++){
            char ch=s[i];
            if(ch=='(' or ch=='{' or ch=='[')
                st.push(ch);
            else{
                if(st.empty())
                    return false;
                else if(ch==')' and st.top()!='(')
                    return false;
                else if(ch=='}' and st.top()!='{')
                    return false;
                else if(ch==']' and st.top()!='[')
                    return false;
                else
                    st.pop();
            }
        }
        return st.empty();
    }
};