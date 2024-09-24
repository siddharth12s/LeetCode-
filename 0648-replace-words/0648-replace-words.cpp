
class Solution {
public:
    int longestprefix(string &s1, string &s2){
        int m = s1.size();
        int n = s2.size();

        int i=0,j=0;
        int len = 0;
        while(i<m and j<n){
            if(s1[i]==s2[j]){
                i++;
                j++;
                len++;
            }else{
                break;
            }
        }

        return len==0?INT_MAX:len;
    }
    string replaceWords(vector<string>& dict, string sentence) {
        stringstream str(sentence);
        string word;

        string ans = "";
        while(str>>word){
            int len = 0;
            int minlen = INT_MAX;
            for(auto x : dict){
                len = longestprefix(word,x);
                if(len==x.size())
                    minlen = min(minlen,len);
            }
            if(minlen==INT_MAX){
                ans += word;
            }else{
                ans += word.substr(0,minlen);
            }
            ans+= " ";
        }
        ans = string(ans.begin(),ans.end()-1);
        return ans;
    }
};