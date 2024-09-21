class Solution {
public:
    string shortestPalindrome(string s) {

        //creating lps
        string reversedString = s;
        reverse(reversedString.begin(),reversedString.end());

        string temp = s + "#" + reversedString;
        int prevlps=0,i=1;
        vector<int> lps(temp.size(),0);
        // cout<<temp;

        while(i<temp.size()){
            while(prevlps>0 and temp[prevlps]!=temp[i]){
                prevlps = lps[prevlps-1];
            }
            if(temp[i]==temp[prevlps]){
                prevlps++;
            }
            lps[i]=prevlps;
            i++;
        }

        int palindromeLength = lps.back();

        string suffix = reversedString.substr(0,s.size()-palindromeLength);
        return suffix + s;
    }
};