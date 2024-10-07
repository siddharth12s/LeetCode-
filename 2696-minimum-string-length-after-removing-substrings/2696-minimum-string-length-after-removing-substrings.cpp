class Solution {
public:
    int minLength(string s) {
        stack<char> st;

        for(auto ch : s){
            if(st.empty()){
                st.push(ch);
                continue;
            }

            if((ch=='B' && st.top()=='A') || (ch=='D' && st.top()=='C')){
                st.pop();
            }else{
                st.push(ch);
            }
        }

        // while(!st.empty()){
        //     cout<<st.top()<<endl;
        //     st.pop();
        // }
        return st.size();
    }
};