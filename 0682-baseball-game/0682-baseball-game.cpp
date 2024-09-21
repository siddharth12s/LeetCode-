class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto s : operations){
            if(s=="+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a+b);
            }else if(s=="D"){
                int a = st.top();
                st.push(2*a);
            }else if(s=="C"){
                st.pop();
            }else{
                st.push(stoi(s));
            }
            if(!st.empty())
                cout<<st.top()<<endl;
        }
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};