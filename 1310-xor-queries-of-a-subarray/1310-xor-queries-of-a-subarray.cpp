class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto q : queries){
            int _xor = 0;
            for(auto i=q[0];i<=q[1];i++){
                _xor ^= arr[i];
            }
            ans.push_back(_xor);
        }

        return ans;
    }
};