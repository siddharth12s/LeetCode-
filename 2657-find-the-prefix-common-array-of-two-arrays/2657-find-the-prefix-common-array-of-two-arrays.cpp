class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;

        for(auto i=0;i<A.size();i++){
            unordered_set<int> st;
            for(auto j=0;j<=i;j++){
                st.insert(A[j]);
            }

            int cnt = 0;
            for(auto j=0;j<=i;j++){
                if(st.count(B[j])){
                    cnt++;
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};