class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int i=1;
        while(ss >> word){
            string temp = word.substr(0,searchWord.size());
            if(temp==searchWord){
                return i;
            }else{
                i++;
            }
        }
        return -1;
    }
};