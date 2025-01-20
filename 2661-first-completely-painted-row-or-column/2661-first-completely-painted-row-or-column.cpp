class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<unordered_set<int>> row(m), col(n);
        unordered_map<int,pair<int,int>> mp;

        for(auto i=0;i<m;i++){
            for(auto j=0;j<n;j++){
                row[i].insert(mat[i][j]);
                col[j].insert(mat[i][j]);
                mp[mat[i][j]] = {i,j};
            }
        }

        for(auto i=0;i<arr.size();i++){
            int row_index = mp[arr[i]].first;
            // cout<<row_index<<endl;
            if(row[row_index].count(arr[i])){
                row[row_index].erase(arr[i]);
            }

            if(row[row_index].size()==0)
                return i;

            int col_index = mp[arr[i]].second;
            if(col[col_index].count(arr[i])){
                col[col_index].erase(arr[i]);
            }

            if(col[col_index].size()==0)
                return i;
        }

        return -1;
    }
};