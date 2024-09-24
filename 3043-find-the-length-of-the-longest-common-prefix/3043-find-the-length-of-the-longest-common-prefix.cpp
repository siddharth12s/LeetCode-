class TrieNode{
     
    public:
    TrieNode* child[10];
    bool isLeaf;
    TrieNode(){
        for(auto i=0;i<10;i++){
            child[i] = nullptr;
        }
    }
};

class Trie{

    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode();
    }


    void insert(int num){
        TrieNode* node = root;
        string s = to_string(num);

        for(char digit : s){

            if(node->child[digit-'0']==nullptr){

                TrieNode * newNode = new TrieNode();
                node->child[digit-'0']=newNode;
            }
            node = node->child[digit-'0'];
        }
    }


    int longestprefixlen(int num){
        TrieNode* node = root;
        string s = to_string(num);
        int len=0;
        for(auto digit : s){
            int idx = digit-'0';
            if(node->child[idx]){
                len++;
                node=node->child[idx];
            }else{
                break;
            }
        }

        return len;
    }
};



class Solution {
public:
    int KMP(string text, string pattern){
        vector<int> lps(pattern.size(),0);
        int i = 0, prevlps=0;
        while(i<pattern.size()){
            if(pattern[prevlps]==pattern[i]){
                prevlps++;
                lps[i]=prevlps;
                i++;
            }else{
                if(prevlps==0){
                    lps[i]=0;
                    i++;
                }else{
                    prevlps=lps[prevlps-1];
                }
            }
        }

        i=0;
        int j=0;
        int len = 0;

        while(i<text.size()){
            if(text[i]==pattern[j]){
                i++;
                j++;
                len++;
            }else{
                break;
            }
        }
        return len;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        int ans = 0;
        Trie trie;
        for(auto x : arr1){
            trie.insert(x);
        }

        for(auto x : arr2){
            int len = trie.longestprefixlen(x);
            ans =max(len,ans);
        }

        return ans;
    }
};