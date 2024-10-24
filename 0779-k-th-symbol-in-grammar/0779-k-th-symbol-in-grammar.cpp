class Solution {
public:
    void fun(string &s, int i){
        if(i==1){
            s+='0';
            return;
        }
        fun(s,i-1);

        string temp = "";
        for(auto ch : s){
            if(ch=='1'){
                temp+="10";
            }else{
                temp+="01";
            }
        }
        s=temp;
    }
    int kthGrammar(int n, int k) {
        string s;
        fun(s,n);
        cout<<s;
        return s[k-1]-'0';
    }
};