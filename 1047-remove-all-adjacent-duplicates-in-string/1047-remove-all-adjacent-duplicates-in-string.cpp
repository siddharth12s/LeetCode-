class Solution {
public:
    string removeDuplicates(string s) {
        
        string ans ="";
        int i=0;
        int n=s.length();
        
        while(i<n){
            if(ans.back()==s[i]){
                ans.pop_back();
            }else{
                ans += s[i];
            }
            i++;
        }
        return ans;
    }
};