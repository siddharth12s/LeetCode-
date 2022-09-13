class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> s;
        int n = tokens.size();
        for(auto i=0;i<n;i++){
            if(tokens[i]=="/" or tokens[i]=="-" or tokens[i]=="*" or tokens[i]=="+"){
                auto a = s.top(); s.pop();
                auto b = s.top(); s.pop();
                if(tokens[i]=="/")  s.push(b/a);
                if(tokens[i]=="*")  s.push(b*a);
                if(tokens[i]=="+")  s.push(b+a);
                if(tokens[i]=="-")  s.push(b-a);
            }
            else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};