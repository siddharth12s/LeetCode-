class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";

        while(s.size()<k){
            string temp = "";
            for(auto ch : s){
                if(ch=='z') temp.push_back('a');
                temp.push_back(ch+1);
            }
            cout<<temp<<endl;
            s+=temp;
        }

        return s[k-1];
    }
};