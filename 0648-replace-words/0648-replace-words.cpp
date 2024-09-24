class TrieNode{
public:
    TrieNode* child[26];
    bool isLeaf=false;

    TrieNode(){
        for(auto i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};

class Trie{
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string key){

        TrieNode* curr = root;

        for(char ch : key){
            int idx = ch-'a';

            if(curr->child[idx]==NULL){
                TrieNode* newNode = new TrieNode();

                curr->child[idx]=newNode;
            }

            curr = curr->child[idx];
        }

        curr->isLeaf=true;
    }

    string search_prefix(string key){
        TrieNode* curr = root;

        for(int i=0;i<key.size();i++){
            int idx = key[i]-'a';

            if(curr->child[idx]==NULL)
                return key;

            curr = curr->child[idx];
            if(curr->isLeaf){
                return key.substr(0,i+1);
            }

        }

        return key;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        
        Trie trie;

        for(auto x : dict){
            trie.insert(x);
        }

        stringstream st(sentence);
        string word;
        string ans = "";
        while(st>>word){
            ans += trie.search_prefix(word);
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};