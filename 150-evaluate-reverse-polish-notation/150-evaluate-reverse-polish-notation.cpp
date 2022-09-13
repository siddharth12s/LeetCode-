class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> s;
        int n = tokens.size();
        int ans=0;
        for(auto i=0;i<n;i++){
            if(tokens[i]=="/" or tokens[i]=="-" or tokens[i]=="*" or tokens[i]=="+"){
                long long int a = s.top();
                s.pop();
                long long int b = s.top();
                s.pop();
                if(tokens[i]=="/"){
                    s.push(b/a);
                }
                else if(tokens[i]=="*"){
                    s.push(b*a);
                }
                else if(tokens[i]=="+")
                    s.push(b+a);
                else
                    s.push(b-a);
            }
            else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};