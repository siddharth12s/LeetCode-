class Solution {
public:
    bool backspaceCompare(string s, string t) {

        stack<char> st1, st2;

        for(auto ch :s){
            if(st1.empty() and ch=='#')
                continue;
            if(ch=='#')
                st1.pop();
            else
                st1.push(ch);
        }

        for(auto ch : t){
            if(st2.empty() and ch=='#')
                continue;
            if(ch=='#')
                st2.pop();
            else
                st2.push(ch);
        }


        string s1,s2;
        while(st1.size()>0){
            s1 += st1.top();
            st1.pop();
        }

        while(st2.size()>0){
            s2 += st2.top();
            st2.pop();
        }


        return s1==s2;
    }
};