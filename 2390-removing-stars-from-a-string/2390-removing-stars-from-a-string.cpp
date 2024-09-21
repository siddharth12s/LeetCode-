class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        string ans;

        for(auto c : s){
            if(c=='*')
                st.pop();
            else
                st.push(c);
        }

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        cout<<ans;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};