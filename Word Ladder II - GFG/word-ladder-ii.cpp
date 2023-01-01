//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
            unordered_set<string> lst;
        for(auto s: wordList){
            lst.insert(s);
        }

        queue<vector<string>>q;
        q.push({beginWord});
        vector<string> t;
        t.push_back(beginWord);
        lst.erase(beginWord);
        vector<vector<string>> ans;
        int level=0;
        while(!q.empty()){
            vector<string> f = q.front();
            q.pop();
            
            if(f.size()>level){
                level++;
                for(auto it: t){
                    lst.erase(it);
                }
            }
            auto last = f.back();

            if(last==endWord){
                if(ans.size()==0)
                    ans.push_back(f);
                else if(ans[0].size()==f.size()){
                    ans.push_back(f);
                }
            }


            for(auto i=0;i<last.size();i++){
                string temp = last;
                for(auto ch='a';ch<='z';ch++){
                    temp[i]=ch;

                    if(lst.count(temp)){
                        f.push_back(temp);
                        q.push(f);
                        t.push_back(temp);
                        f.pop_back();
                    }
                }
            }

        }

        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends