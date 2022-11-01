class Solution {
public:
    
    void solve(vector<string> &ans, string &s, int i,int n){
        if(i==n){
            ans.push_back(s);
            return;
        }
        
        char c = s[i];  
        if(islower(c))
            s[i]=toupper(c);
        else
            s[i]=tolower(c);
        solve(ans,s,i+1,n);
        if(isalpha(s[i])){
            s[i]=c;
            solve(ans,s,i+1,n);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string t="";
        int n = s.length();
        solve(ans,s,0,n);
        return ans;
    }
};