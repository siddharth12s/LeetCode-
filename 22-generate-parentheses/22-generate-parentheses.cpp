class Solution {
public:
    void generate(string s,int open,int close,int n,vector<string> &ans){
        if(open==n and close==n){
            ans.push_back(s);
            return;
        } 
        
        if(open<n){
            generate(s + "(",open+1,close,n,ans);
        }
        if(open>close){
            generate(s + ")",open,close+1,n,ans);
        }
    }
//     void generate(int n, int open, int close,string s, vector<string>& ans)
// {

//     if (open == n && close == n) {
//         ans.push_back(s);
//         return;
//     }
//     if (open < n) {
//         generate(n, open + 1, close, s + "(",ans);
//     }

//     if (close < open) {
//         generate(n, open, close + 1, s + ")", ans);
//     }
// }
    vector<string> generateParenthesis(int n) {
     vector<string> ans;
    generate("", 0, 0, n, ans);
        return ans;
    }
};