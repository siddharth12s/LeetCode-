class Solution {
public:

    string invert(string s){
        for(auto &ch : s){
            if(ch=='0'){
                ch='1';
            }else{
                ch='0';
            }
        }
        return s;
    }

    string kthstring(int i){
        if(i==1){
            return "0";
        }
        string k = kthstring(i-1);
        cout<<k;
        string invert_k = invert(k);
        reverse(invert_k.begin(),invert_k.end());
        string temp = k + "1" + invert_k;
        return temp;
    }
    char findKthBit(int n, int k) {
        return kthstring(n)[k-1];
    }
};