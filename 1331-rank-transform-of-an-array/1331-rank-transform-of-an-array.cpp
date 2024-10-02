class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st;

        for(auto x : arr){
            st.insert(x);
        }

        unordered_map<int,int> rank;
        int r = 1;
        for(auto x : st){
            rank[x] = r;
            r++;
        }

        for(auto i=0;i<arr.size();i++){
            arr[i] = rank[arr[i]];
        }

        return arr;
    }
};