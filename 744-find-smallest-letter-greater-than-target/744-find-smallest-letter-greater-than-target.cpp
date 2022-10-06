class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l =0, r = n-1;
        char res=letters[0];
        
        while(l<=r){
            int m = l + (r-l)/2;
            
            if(letters[m]==target)
                l=m+1;
            else if(letters[m]<target)
                l=m+1;
            else{
                res=letters[m];
                r=m-1;
            }
        }
        return res;
    }
};