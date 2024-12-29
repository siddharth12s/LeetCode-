class Solution {
public:
    string answerString(string word, int numFriends) {
        
        vector<string> w;
        int len = word.size();
        if(numFriends==1)
            return word;
        
        int max_len = len - numFriends + 1;
        string ans = "";
        for(auto i=0;i<len;i++){
            string temp = word.substr(i,min(len-i,max_len));
            if(temp>ans){
                ans=temp;
            }

        }

        // sort(w.begin(),w.end());

        return ans;
    }
};