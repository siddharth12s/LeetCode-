class Solution {
public:
    string shortestPalindrome(string s) {
        // int len = s.size();
        // string ans = "";


        // int start = 0;
        // int end = len-1;
        // int idx = 0;
        // while(start<=end){
        //     string temp = "";
        //     if(s[start]!=s[end] and start<end){
        //         temp += s[end];
        //         temp += s[end];
        //         ans.insert(idx,temp);
        //         end--;
        //     }else if(s[start]==s[end] and start==end){
        //         temp+= s[end];
        //         ans.insert(idx,temp);
        //         end--;
        //     }else{
        //         temp+=s[end];
        //         temp+=s[end];
        //         ans.insert(idx,temp);
        //         start++;
        //         end--;
        //     }
        //     idx++;
        // }
        // return ans;
                string reversedString = s;
        // Reverse the original string
        reverse(reversedString.begin(), reversedString.end());

        // Iterate through the string to find the longest palindromic prefix
        for (int i = 0; i < s.size(); ++i) {
            // memcmp to avoid creating substrings
            if (!memcmp(s.c_str(), reversedString.c_str() + i, s.size() - i)) {
                // Append the necessary part to make the palindrome
                return reversedString.substr(0, i) + s;
            }
        }
        // Fallback case, append the whole reversed string to the original
        // string
        return reversedString + s;
        
    }
};