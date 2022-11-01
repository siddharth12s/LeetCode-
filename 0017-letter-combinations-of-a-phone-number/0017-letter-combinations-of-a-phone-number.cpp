class Solution {
public:
    
    void solve(vector<string>& ans, string m[], string &digits,int i,string &t){
        
        if(i>=digits.length()){
            ans.push_back(t);
            return;
        }
        
        int num = digits[i] - '0';
        for(auto j = 0; j< m[num].length(); j++){
            t.push_back((m[num])[j]);
            solve(ans,m,digits,i+1,t);
            t.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        string m[10]= {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        if(digits.length()==0)
            return ans;
        string t ="";
        solve(ans,m,digits,0,t);
        return ans;
    }
};