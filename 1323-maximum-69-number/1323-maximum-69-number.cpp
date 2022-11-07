class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        size_t f = s.find("6");
        if(f==string::npos)
            return num;
        else{
            s[f]='9';
        }
        int size = s.length();
        int i = 0;
        num=0;
        while(i<size){
            num += s[i]-'0';
            i++;
            num*=10;
        }
        return num/10;
    }
};