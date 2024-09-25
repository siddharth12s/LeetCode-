class TrieNode{
    public:
        TrieNode* child[26];
        int cnt = 0;
        TrieNode(){
            for(auto i=0;i<26;i++){
                child[i]=0;
            }
        }
};

class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            root = new TrieNode();
        }

        void insert(string key){
            TrieNode* curr = root;
            for (auto ch : key){
                int idx = ch-'a';

                if(curr->child[idx]==nullptr){
                    TrieNode* newNode = new TrieNode();
                    curr->child[idx]= newNode;
                }
                curr->child[idx]->cnt++;
                curr = curr->child[idx];
            }
        }

        int count(string key){
            int ans = 0;
            TrieNode* curr = root;
            for(auto ch : key){
                int idx = ch-'a';

                ans += curr->child[idx]->cnt;
                curr=curr->child[idx];
            }

            return ans;
        }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        Trie trie;
        for(auto word : words){
            trie.insert(word);
        }

        for(auto word : words){
            ans.push_back(trie.count(word));
        }

        return ans;
    }
};