class Solution {
public:
    int kmp(string text, string pattern){
        int m =text.size();
        int n =pattern.size();

        vector<int> lps(n+1,0);

        int i=1;
        int prevlps=0;
        while(i<n){
            if(pattern[prevlps]==pattern[i]){
                prevlps+=1;
                lps[i]=prevlps;
                i++;
            }else{
                if(prevlps==0){
                    lps[i]=0;
                    i++;
                }else{
                    prevlps = lps[prevlps-1];
                }
            } 
        }

        i=0;
        int j=0;

        while(i<m){
            if(text[i]==pattern[j]){
                i++;
                j++;
            }else{
                if(j==0){
                    i++;
                }else{
                    j=lps[j-1];
                }
            }

            if(j==pattern.size()){
                return i-pattern.size()==0;
            }
        }

        return 0;
    }
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for(auto &x : words){
            cnt += kmp(x,pref);
        }

        return cnt;
    }
};