class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
        int i = 0, j = n-1;
        
        while(i<j){
            if((tolower(s[i])=='a' or tolower(s[i])=='e' or tolower(s[i])=='i' or tolower(s[i])=='o' or tolower(s[i])=='u') and (tolower(s[j])=='a' or tolower(s[j])=='e' or tolower(s[j])=='i' or tolower(s[j])=='o' or tolower(s[j])=='u')){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if((tolower(s[i])=='a' or tolower(s[i])=='e' or tolower(s[i])=='i' or tolower(s[i])=='o' or tolower(s[i])=='u') and !(tolower(s[j])=='a' or tolower(s[j])=='e' or tolower(s[j])=='i' or tolower(s[j])=='o' or tolower(s[j])=='u')){
                j--;
            }
            else if(!(tolower(s[i])=='a' or tolower(s[i])=='e' or tolower(s[i])=='i' or tolower(s[i])=='o' or tolower(s[i])=='u') and (tolower(s[j])=='a' or tolower(s[j])=='e' or tolower(s[j])=='i' or tolower(s[j])=='o' or tolower(s[j])=='u')){
                i++;
            }
            else{
                i++;
                j--;
            }
        }
        
        return s;
    }
};