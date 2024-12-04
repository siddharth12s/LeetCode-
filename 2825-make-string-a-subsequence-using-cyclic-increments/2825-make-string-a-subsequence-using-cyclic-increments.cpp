class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        // int cnt=1;

        int i=0,j=0;
        int m=str1.size();
        int n =str2.size();

        while(i<m and j<n){
            if(str1[i]==str2[j]){
                i++;
                j++;
            }else{
                int circular_val = (str1[i]-'a'+1)%26;
                char ch = 'a' + circular_val;
                cout<<ch<<endl;
                if(ch==str2[j]){
                    i++;
                    j++;
                    // cnt--;
                }else if(ch!=str2[j] ){
                    i++;
                }
            }
        }

        // cout<<i<<","<<j;
        if(j!=n)   return false;
        return true; 
    }
};