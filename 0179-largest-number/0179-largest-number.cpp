class Solution {
public:
    static bool compare(string a, string b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for(auto x : nums){
            temp.push_back(to_string(x));
        }

        sort(temp.begin(),temp.end(),compare);
        string ans = "";
        for(int i = 0;i<temp.size();i++){
            ans += temp[i];
        }

        return ans[0]=='0'?"0":ans;
    }
};