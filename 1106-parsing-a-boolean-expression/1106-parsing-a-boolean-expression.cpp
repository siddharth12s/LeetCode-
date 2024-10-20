class Solution {
public:
    bool parseBoolExpr(string exp) {
        bool ans=true;
        int check = -1;
        unordered_map<char,int> m;
        m['f']=0;
        m['t']=1;
        // int ans;

        stack<char> oper,ex;
        for(auto ch : exp){
            if(ch==',')
                continue;
            if(ch=='&' or ch=='!' or ch=='|'){
                oper.push(ch);
            }else{
                if(ch==')'){
                    if(check==-1)
                        check = m[ex.top()];
                    cout<<oper.top()<<endl;
                    while(ex.top()!='('){
                        if(oper.top()=='&'){
                            check &= m[ex.top()];
                        }else if(oper.top()=='|'){
                            check |= m[ex.top()];
                        }else if(oper.top()=='!'){
                            check = !(m[ex.top()]);
                        }
                        ex.pop();
                    }
                    ex.pop();
                    cout<<check<<endl;
                    if(check==0){
                        ex.push('f');
                    }else{
                        ex.push('t');
                    }
                    // ex.push((check));
                    cout<<ex.top()<<"lolo"<<endl;
                    oper.pop();
                    // cout<<check<<endl;
                }else{
                    ex.push(ch);
                }
            }
        }
        // cout<<
        return check;
    }
};