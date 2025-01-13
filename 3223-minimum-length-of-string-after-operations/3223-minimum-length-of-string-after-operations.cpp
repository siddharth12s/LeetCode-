class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> m1,m2;

        int ans = s.length();
        for(auto ch : s){
            m1[ch]++;
            if(m1.find(ch)!=m1.end()){
                if(m1[ch]==3){
                    ans -= 2;
                    // m1.erase(ch);
                    m1[ch]-=2;
                }
            }
            cout<<m1[ch]<<endl;
        }

        return ans;
    }
};