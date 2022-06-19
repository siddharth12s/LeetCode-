class Solution {
public:
//     vector<string> ans;
//     void generate(string s,int i,int open,int close,int n){
//         if(open==n and close==n){
//             ans.push_back(s);
//             return;
//         } 
        
//         if(open<n){
//             s += '(';
//             generate(s,i+1,open+1,close,n);
//         }
//         if(open>close){
//             s += ')';
//             generate(s,i+1,open,close+1,n);
//         }
//     }
    void generate(int n, int open, int close,string s, vector<string>& ans)
{

    if (open == n && close == n) {
        ans.push_back(s);
        return;
    }
    if (open < n) {
        generate(n, open + 1, close, s + "(",ans);
    }

    if (close < open) {
        generate(n, open, close + 1, s + ")", ans);
    }
}
    vector<string> generateParenthesis(int n) {
     vector<string> ans;
    generate(n, 0, 0, "", ans);
        return ans;
    }
};